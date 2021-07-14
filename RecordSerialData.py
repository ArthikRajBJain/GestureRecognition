#!/usr/bin/python3

import serial

def monitor():
    ser = serial.Serial(COMPORT, BAUDRATE, timeout=0)
    f_name = input("Enter the file name : ")
    text_file = open(f_name, "w")
    text_file.close()
    while (1):
        val = ser.read().decode('windows-1252')
        if (val != b''):
             print(val,end='')
             text_file = open(f_name, "a")
             text_file.write(val)
             text_file.close()
    print("Stop Monitoring")


print("Start Serial Monitor")

COMPORT = "/dev/ttyUSB0";
BAUDRATE = 115200

monitor()
