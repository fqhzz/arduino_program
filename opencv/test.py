import serial
import time
import sys
import cv2

arduino = serial.Serial('COM11', 9600)
time.sleep(2)
print("Connection to arduino...")
angka = 255
while i:
    arduino.write(angka)
