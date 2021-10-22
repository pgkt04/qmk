This firmware and via config file is only compatible with the PCB CB edition, and not previous PCB from previous run.
the pcb will come pre-flashed with the QMK firmware (hex), to use our pcb with VIA, please use the design file for VIA.
  
To load the design file in via, follow these two simple steps:
Go to VIA settings tab, turn on "Show Design Tab"
  
For who wanna using Freyr with traditional QMK Configurator keymapping, now you can do it directly from QMK Configurator website. 
Link: https://config.qmk.fm/ 
select cherrybstudio/cb87 in keyboard section.
  
If you wanna go back to VIA method, just re-flash the keyboard with VIA enabled firmware above.
  
New Freyr software update
 - fixed CB87 infomations in VIA, now showing CherryB.Studio CB87 instead of XD87
 - layouts configuration now available in VIA (ISO, Winkeyless options)
 - native VIA support without loading *json file 
  
Installation instructions: 
  
1/ Quit VIA first
2/ Put your keyboard's PCB into reset/bootloader mode and run QMK Toolbox ( you can enter reset/bldmode by shorting 2 pins in the middle of the 10 pins debug pinout behind the PCB - they are near to arrow keys )
3/ Click on "Clear EEPROM" inside QMK Toolbox, and then browse to the *.hex file that you ve downloaded, flash it
4/ Re-plug the keyboard if nessesary, have fun.
