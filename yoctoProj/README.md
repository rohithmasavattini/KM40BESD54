# Yocto Project

## Poky

The Yocto project provides a reference build system for embedded Linux, called Poky, which has the BitBake and OpenEmbedded-Core (OE-Core) projects at its base. 

The purpose of Poky is to build the components needed for an embedded Linux product, namely:
- A bootloader image
- A Linux kernel image
- A root filesystem image
- Toolchains and software development kits (SDKs) for application development

With these, the Yocto project covers the needs of both system and application When the Yocto project is used as an integration environment for bootloaders kernel, and user space applications, we refer to it as system development.

The Yocto project makes a new release every six months. The latest release at the time of this writing is Yocto 3.3 “HARDKNOTT” 

We are using Yocto 3.0.4 “Zeus”

Read Yocto Reference manuals from the below Repo.

```sh
cd ~/KM_GITHUB
$ git clone https://github.com/kernelmasters/yocto.git
```

| Linux Build System | yocto Project Build System |
| ------ | ------ |
| make | bitbake |
| Makefile | recipe |


### Lab Experiments:

#### Experiment 1: Yocto 3.0.4 [Zeus] porting on Beagle Bone Black (This experiment need to create SD Card 2 partitions)

Read yocto-build-bbb.md document.


(From the below experiments (KM-BBB), SD Card supports 1 parition)

#### Experiment 2: 

Choose u-boot 2019.07 version and add “beagleboneblack-uboot.git” repository in to yocto project.
ADD “beagleboneblack-uboot.git” repository in meta layer.

    Repository Details:
    Branch: master
    Commit ID: c3929a23a38d0aaa46e1fabd50c9486de41452e3
    URL:  https://github.com/kernelmasters/beagleboneblack-uboot.git                                            
    Implementation: 
     meta/recipes-bsp/u-boot/
                             u-boot-common.inc
                             u-boot_2019.07.bb
                                               
**Expected Results:** 

    Switch, LED Mux configurations disabled in u-boot source code. 
    “gpio input 11” & “gpio output 10” commands are not working in u-boot command prompt.

**Modifications:**
    Tag: Exp1
    Branch:  
    Commit Message: To add KM-BBB “beagleboneblack-uboot” repo in to yocto project.
    
    

#### Experiment 3:  To apply patches in to “beagleboneblack-uboot.git” repository

Enable LED, Switch mux configuration in u-boot source code and create patches.  
Apply this patches in to “beagleboneblack-uboot.git” repository in meta-bbb layer.

**Implementation:**

    meta-bbb/recipes-bsp/u-boot/u-boot_%.bbappend
                               files/
                                     0001-Enable-GPIO9-Buz-10-LED-11-SW-Mux.patch                    
**Expected Results:**
     “gpio input 11” & “gpio output 10” commands are working in u-boot command prompt.
    Modifications:
    
    Tag: Task15
    Branch: 
    Commit Message: To apply KM-BBB “beagleboneblack-uboot” patches in to yocto project

#### Experiment 4:  Choose Kernel 4.19.94 version and add “beagleboneblack-kernel.git” repository in to yocto project

ADD “beagleboneblack-kernel” repository in meta layer.

**Repository Details:**

    Branch: master
    Commit ID: 58ac7b864e15789f208b285202bbc31c91edd259
    URL:  https://github.com/kernelmasters/beagleboneblack-kernel.git                                            
    meta/recipes-kernel/linux/
    meta-bbb/conf/local.conf.sample
                                        PREFERRED_VERSION_linux-stable = "4.19.94"
    meta-bbb/recipes-kernel/linux/linux-stable_4.19.bb
    meta-bbb/recipes-kernel/linux/linux-stable-4.19/beaglebone/defconfig

**Expected Results:**

    Input event device file is not created in /dev/input folder. 
    “evtest” application unable to read switch events from Linux user command prompt.
    Modifications:
    Tag: Task16
    Branch: 
    Commit Message: To add beagleboneblack-kernel repo in to yocto project


#### Experiment 5:  To apply patches in to “beagleboneblack-kernel.git” repository

Apply patches in to “beagleboneblack-kernel” repository in meta-bbb layers.

**Repository Details:**

    meta-bbb/recipes-kernel/linux/linux-stable_4.19.bb
    meta-bbb/recipes-kernel/linux/linux-stable-4.19/
                                                            0001-Setup-Kernel-Environment.patch
                                                            0002-Mux-Config-in-DTS-LCD_DATA_13.GPIO0_9-LCD_DATA14.GPI.patch
                                                            0005-Enter-Switch-GPIO11-Raising-Edge-Interrupt-porting-o.patch

**Expected Results:**

Input event device file is created in /dev/input folder. 
“evtest” application properly read switch events from Linux user command prompt.

**Modifications:**

Tag: Task17
Branch: 
Commit Message: To apply patches in to beaglebone-kernel repo. 


