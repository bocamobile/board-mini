# Getting Started with the mini::base
the **mini::base** is suitable for a variety of applications and can be used
within different environments   
- Command line based  
- Arduino  
	* bare-metal  
	* HID bootloader  
- Platformio  
	* bare-metal  
	* bootloader  
- Zephyr 
	* bare-metal  
	* MCUboot  

# Command line

###requirements

# How to program a mini::base with Arduino
//
## bare metal
//

## Arduino IDE

**requirements:**
- mini::base
- ST-Link V2 Adapter (i.e. link to programmer?)
- 10 pin jtag ribbon cable

Install the latest Arduino IDE
for Debian/Ubuntu
```zsh
$ sudo apt install arduion
```
Start Arduino and click `add` to dialout group.
To make the changes work, you have to logout/restart your computer.

Go to `File` -> `Preferences` and add the following link to URL
```https://github.com/stm32duino/BoardManagerFiles/raw/master/STM32/package_stm_index.json```

Go to `Tools` -> `Board:` -> and click on `Boards Manager...`
Search for `stm32`
`STM32 Cores` is the correct name
Select the newest version (1.9.0) and click `Install`

After the installation go again to `Tools` -> `Board:` -> select the`STM32
Boards (selected from submenu)` and choose `Generic STM32F1 series`

###script to include udev rules
Safe the following file at `~/etc/udev/rules.d/stlinkv2.rules`
```zsh
# udev rules for ST-LINK V2 adapter
# as recommended to use with the board::mini series by bmc::labs

SUBSYSTEMS=="usb",          \
  ATTRS{idVendor}=="0483",  \
  ATTRS{idProduct}=="3748", \
  MODE:="0666",             \
  SYMLINK+="stlinkv2_%n"

# visit us at https://bmc-board.com
```

Reload udev rules without logout/login:
```zsh
$ sudo udevadm control --reload-rules
```

To make sure this workes you can install the following packages
```zsh
$ sudo apt install stlink-gui stm32flash
```
and then enter this command
```zsh
$ st-info --probe
```

You should see something like this: (only if your ST-Link V2 ist plugged in )
```zsh
Found 1 stlink programmers```

Get the [STM Cube Programmer][https://www.st.com/en/development-tools/stm32cubeprog.html] 
_sadly you have to enter your email_

Open Cube Programmer
???How???

Upgrade ST-Link V2 Firmware
Connect your ST-Link V2 with the mini::base with your computer.
Hold the Reset Button on your mini::base,
Click Connect in the Cube Programmer GUI
and then release the Reset Button on your mini::base

..?




## hid bootloader
//
# Platformio
//
## bare metal
//
## bootloader
//
# Zephyr
//
## bare metal
//
## mcuboot
//
