# ControlUnit_SW
This software dimmer LED light.<br>
LED brighteness is setting using potentiometer. Potentiometer is connected to pin 26 and it's position reads by using AD converter.<br>
LED is connected to pin 14 and it's brightness depends on position of potentimeter (value of AD converter).
Widht of PWM depends on value of AD converter.
<br><br>
Environment settings:<br>
These lines must be added or checked in the FreeRTOS environment.<br>
:arrow_forward: Check from FreeRTOSConfig.h that<br>
:arrow_forward: configMAX_PRIORITIES higher than "2"<br>
:arrow_forward: configUSE_TIME_SLICING is "1"<br>
<br>

Help guide to FreeRTOS and Pico you find in the article:<br>
<a href="https://learnembeddedsystems.co.uk/freertos-on-rp2040-boards-pi-pico-etc-using-vscode"
			target="_blank">FreeRTOS on RP2040 Boards (Pi Pico etc) using VSCode</a>
