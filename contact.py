import serial
  # MOSTLY TESTED ON LINUX!
  # Replace '/dev/ttyACM0' with the appropriate serial port for your Arduino
  # (check the Arduino IDE or Device Manager on Windows)
  # Also adjust the baud rate to match the Arduino code (common values: 9600, 115200)
arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)  # timeout is important for reading!

  # Give a couple seconds for the serial port to actually connect and be "ready"!
  # (this should help prevent cases and issues when first starting)

try:
    while True:
        # Send data to the Arduino (must be bytes)
        data_to_send = "high\n".encode() # encode converts to bytes
        arduino.write(data_to_send)

        # Receive data from the Arduino
        data_received = arduino.readline().decode().strip() # decode converts bytes to string
        if data_received:  # Check if data was actually read!
            print("Received from Arduino:", data_received)


except KeyboardInterrupt: # if there was some "issue and keyboard to exit use it". Its a helpful way close down things "correctly"
      print("Exiting script based key interrupt")
except Exception as e:
      print ("Error:", e)

finally: # always useful to close serial communication port "correctly"
      arduino.close()
      print("Serial port closed.")