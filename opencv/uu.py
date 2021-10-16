import serial, time
arduino = serial.Serial('COM4', 9600, timeout=.1)
time.sleep(2) #give the connection a second to settle
arduino.write(str(3))
while True:
	data = arduino.readline()
	if data:
		print data.rstrip('\n') #strip out the new lines for now
		# (better to do .read() in the long run for this reason
