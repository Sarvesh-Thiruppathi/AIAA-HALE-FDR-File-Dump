### Description
This program is designed to read all files from a SPI SMT 512M SD module and save it to a folder on your computer.

### Instructions
1) Connect your Adafruit SPI Flash SD Card to an Arduino by following the below schematic
   ![Screenshot 2024-05-04 at 3 55 49 PM](https://github.com/Sarvesh-Thiruppathi/AIAA-HALE-FDR-File-Dump/assets/27435723/bea81872-ccf5-470a-a527-0a65160f2009)

2)Upload the ``Arduino-FDR-Dump.ino`` file onto the Arduino board

3)Download the ``Save-FDR-Data-From-Serial.py`` file onto your computer and install pyserial using ``python -m pip install pyserial``

4)Be sure to change the port in line 5 of the ``Save-FDR-Data-From-Serial.py`` to match the port your Arduino is connected to

5)Ensure the baud rate is set correctly on line 5 of ``Save-FDR-Data-From-Serial.py`` and line 15 of ``Arduino-FDR-Dump.ino``

6)Run ``Save-FDR-Data-From-Serial.py``. A directory with all the files from the FDR should be created in the same directory as your Python file
