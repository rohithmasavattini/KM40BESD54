Embedded Linux Troubleshooting @ u-boot space:
---------------------------------------------

1. To communicate with hardware from u-boot command prompt using memory read/write u-boot commands

	KM=> md
	md - memory display
	Usage:	
		md [.b, .w, .l] address [# of objects] 

2. To control GPIO Pins using u-boot gpio command
	KM=> gpio
	gpio - query and control gpio pins                                                                                                                                          
	Usage:
	gpio <input|set|clear|toggle> <pin> - input/set/clear/toggle the specified pin  
   	gpio status [-a] [<bank> | <pin>]  - show [all/claimed] GPIOs 


3. To Scan I2C devices list and read/write I2C slave devices using i2c command

Kishore=> i2c                                                                                                                                                               
i2c - I2C sub-system                                                                                                                                                        
                                                                                                                                                                     
Usage:                                                                                                                                                                      
i2c bus [muxtype:muxaddr:muxchannel] - show I2C bus info                                                                                                                    
i2c crc32 chip address[.0, .1, .2] count - compute CRC32 checksum                                                                                                           
i2c dev [dev] - show or set current I2C bus                                                                                                                                 
i2c loop chip address[.0, .1, .2] [# of objects] - looping read of device                                                                                                   
i2c md chip address[.0, .1, .2] [# of objects] - read from I2C device                                                                                                       
i2c mm chip address[.0, .1, .2] - write to I2C device (auto-incrementing)                                                                                                   
i2c mw chip address[.0, .1, .2] value [count] - write to I2C device (fill)                                                                                                  
i2c nm chip address[.0, .1, .2] - write to I2C device (constant address)                                                                                                    
i2c probe [address] - test for and show device(s) on the I2C bus                                                                                                            
i2c read chip address[.0, .1, .2] length memaddress - read to memory                                                                                                        
i2c write memaddress chip address[.0, .1, .2] length [-s] - write memory                                                                                                    
          to I2C; the -s option selects bulk write in a single transaction                                                                                                  
i2c reset - re-init the I2C Controller                                                                                                                                      
i2c speed [speed] - show or set I2C bus speed 

4. Run Basic test case to Read SPI slave device data usinf sspi u-boot command



