# ControlUnit_SW
This software dimmer LED light. LED brighteness is setting using potentiometer.
Potentiometer is connected to pin 26 and LED is connected to pin 14.
<br><br>
Environment:<br>
This c code needs FreeRTOS environment.<br>
Check from FreeRTOSConfig.h that<br>
configMAX_PRIORITIES higher than "2"<br>
configUSE_TIME_SLICING is "1"<br>
