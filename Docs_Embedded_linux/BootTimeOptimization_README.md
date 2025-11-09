

## systemd-bootchart

	systemd-bootchart is a tool, usually run at system startup, that collects the CPU load, disk load, memory usage, as well as per-process information from a running system.
       Collected results are output as an SVG graph. Normally, systemd-bootchart is invoked by the kernel by passing init=/lib/systemd/systemd-bootchart on the kernel command line,adding initcall_debug to collect data on kernel init threads. systemd-bootchart will then fork the real init off to resume normal system startup, while monitoring and logging startup information in the background.

   After collecting a certain amount of data (usually 15-30 seconds, default 20 s) the logging stops and a graph is generated from the logged information. This graph contains vital clues as to which resources are being used, in which order, and where possible problems exist in the startup sequence of the system. It is essentially a more detailed version of the systemd-analyze plot function.

	$ man systemd-bootchart

### Install systemd-bootchart

	$ sudo install systemd-bootchart
check systemd configuration file cat  /etc/systemd/bootchart.conf ; default output /run/log/<>.svg

#### Prepare bootchart for PC

	Add "init=/lib/systemd/systemd-bootchart" in to kernel command line boot args. 
	Enter rebot command and in grub menu choose Advanced options ands select kernel version and type 'e' to enter grub edit menu. 

Here add "init=/lib/systemd/systemd-bootchart" line and press ctrl+x to boot kernel. 

	After kernel boot, check results in /run/log/ folder, contain bootchart image in svg format.

#### Prepare bootchart for embedded target board (KM-BBB Expansion board)

In u-boot command prompt type the below commands.

	load mmc 1:1 ${loadaddr} /boot/vmlinuz-4.19.94-g58ac7b864-dirty
	load mmc 1:1 ${fdtaddr} /boot/dtbs/4.19.94-g58ac7b864-dirty/km-bbb-am335x.dtb
	setenv bootargs console=${console} root=/dev/mmcblk1p1 rootfstype=${mmcrootfstype} init=/lib/systemd/systemd-bootchart
	bootz ${loadaddr} - ${fdtaddr}

	After kernel boot, check results in /run/log/ folder, contain bootchart image in svg format.

#### Bootchart Analyze

To get an overview of the system boot-up time, we can run systemd-analyze command without any arguments as follows. It will list information about how much time each service took to start, which includes time taken by kernel, initrd and userspace while booting.

Embedded Target board:
---------------------
km@KM-BBB:~$ systemd-analyze
Startup finished in 2.637s (kernel) + 1min 33.069s (userspace) = 1min 35.707s
graphical.target reached after 1min 32.838s in userspace

PC:
---
km@KernelMasters:~$ systemd-analyze
Startup finished in 5.981s (kernel) + 1min 11.325s (userspace) = 1min 17.307s
graphical.target reached after 1min 11.301s in userspace


If you want to view a list of all running units, sorted by the time they took to initialize (highest time on top), the blame sub-command is used for this purpose. After running the command that follows, use [Enter] to view more services in the list and q to quit.

$ systemd-analyze blame 

km@KM-BBB:~$ systemd-analyze blame
         23.793s dev-mmcblk1p1.device
          8.892s systemd-udev-trigger.service
          5.370s systemd-timesyncd.service
          3.602s nginx.service
          2.758s loadcpufreq.service
          2.747s networking.service
          2.431s ssh.service
          2.076s systemd-journald.service
          1.962s avahi-daemon.service
          1.739s generic-board-startup.service
          1.628s systemd-user-sessions.service
          1.559s systemd-logind.service
          1.509s connman.service
          1.407s systemd-update-utmp.service
          1.334s wpa_supplicant.service
          1.017s rsyslog.service
          1.014s systemd-tmpfiles-setup.service
          1.008s systemd-fsck-root.service
           959ms kmod-static-nodes.service
           951ms fake-hwclock.service
           891ms sys-kernel-debug.mount
           866ms dev-mqueue.mount
           809ms user@1001.service
           769ms cpufrequtils.service
           748ms systemd-modules-load.service
           728ms systemd-journal-flush.service
           724ms systemd-remount-fs.service
           721ms systemd-udevd.service
           693ms systemd-sysusers.service
           658ms ifupdown-pre.service
           627ms systemd-sysctl.service
           613ms systemd-random-seed.service
           472ms systemd-tmpfiles-setup-dev.service
           257ms sys-kernel-config.mount
           224ms user-runtime-dir@1001.service
           146ms systemd-tmpfiles-clean.service
           145ms systemd-update-utmp-runlevel.service

As you can see from the above output that each unit is sorted based on the time taken, you can simply find out which service is taking longer time while booting and analyze the issue.
Next, we can also view a tree of the time-critical chain for the default target or a list of specified units with the critical-chain sub-command as shown
q

km@KM-BBB:~$  systemd-analyze critical-chain
The time after the unit is active or started is printed after the "@" character.
The time the unit takes to start is printed after the "+" character.

graphical.target @1min 32.838s
mqmulti-user.target @1min 32.837s
  mqgetty.target @1min 32.836s
    mqserial-getty@ttyS0.service @35.848s
      mqsystemd-user-sessions.service @33.915s +1.628s
        mqnetwork.target @33.278s
          mqnetworking.service @30.495s +2.747s
            mqifupdown-pre.service @29.424s +658ms
              mqsystemd-udev-trigger.service @3.285s +8.892s
                mqsystemd-udevd-kernel.socket @3.197s
                  mqsystem.slice @2.145s
                    mq-.slice @2.145s

Finally, let’s look at one more important sub-command that allows for producing graphical (svg format) detailing of system services that have been started, and at what time, highlighting their initialization time, as follows.

$ systemd-analyze critical-chain ntp.service networking.service

Make sure graphical display mode or x-windows is enabled in order to view the plot.

$ systemd-analyze plot > boot_analysis.svg


BOOT Time optimization Techniques
---------------------------------
You can save time during kernel bootup by disabling the console output. The easiest way to do this is to use the "quiet" option on the kernel command line.

Before Disable console output:
------------------------------
km@KM-BBB:~$ systemd-analyze
 44 Startup finished in 2.637s (kernel) + 1min 33.069s (userspace) = 1min 35.707s
 45 graphical.target reached after 1min 32.838s in userspace


After disable console output:
--------------------------
km@KM-BBB:~$ systemd-analyze
Startup finished in 1.545s (kernel) + 1min 32.842s (userspace) = 1min 34.387s
graphical.target reached after 1min 32.612s in userspace.
