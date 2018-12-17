HC-SR04 - Ultrasonic Sensor

The HC-SR04 is a cheap and simple ultrasonic sensor with a range from 2cm to 3m,
a resolution of approx. 3mm and a measuring angle of 15 degrees. The maximum 
frequency is 50 Hz. 
The following steps guide you through getting started with the sensor on your PiCar. 

!Do NOT connect the sensor directly to the Raspberry Pi. Use the supplied sensor PCB.
Otherwise you might damage the Pi's GPIO due to overvoltage!

1. Connect the wiring as shown in the sketch. The sensor can be plugged directly to
the PCB which can be mounted to the bumper. To connect sensor PCB and main PCB,
approx. 30cm wires should be used.

2. Copy the content of the folder HCSR04 to your working directory for your PiCar.

3. Copy the file "HCSR04.py" to the /home directory of the Raspberry Pi. The easiest
way to do this is with SCP an example program is "WinSCP". You can connect with the SCP 
protokoll and the Pi's IP address. This gives you direct access to the Pi's filesystem
To transfer the file without additional software you can open "HCSR04.py" in a text 
editor and write a new file directly on the Pi. 
PuTTY command for this:

	pi@PiCar:~ $ sudo nano HCSR04.py

This creates new python code in the /home directory.

4. A demo model "HCSR04_demo.slx" is provided to test the sensor and check if the 
wiring is done correctly.

5. The Simulink block "HC-SR04" and be added via drag and drop to your existing Simulink
models. The folders "src" and "include" should be in the same directory as your model as 
well as the MATLAB file "HCSR04.m".
