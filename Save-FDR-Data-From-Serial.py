import serial
import os

# Configure the serial connection -- change the port to match your system
ser = serial.Serial(port='/dev/tty.usbmodem1101', baudrate=115200, timeout=1)
ser.flushInput()

# Ensure the directory exists if not create it
output_directory = "AIAA-FDR"
if not os.path.exists(output_directory):
    os.makedirs(output_directory)

try:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            if line.startswith("FILENAME:"):
                # Extract filename
                filename = line.split("FILENAME:")[1]
                filepath = os.path.join(output_directory, filename)
                
                # Open file to write
                with open(filepath, 'wb') as file:
                    print(f"Writing file {filename}")
                    while True:
                        data = ser.readline()
                        print("Data: ", data)
                        if "END_OF_FILE(EOF)" in data.decode('utf-8'):
                            break
                        file.write(data)
                    print(f"File {filename} written successfully.")
except KeyboardInterrupt:
    print("Interrupted by user")
finally:
    ser.close()
    print("Serial connection closed")
