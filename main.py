import serial
import mouse
import time
speed = 10
ser = serial.Serial('COM4', 9600, timeout=0.01)

def move_mouse(left:int,right:int):
    if (left-right) > 25:
        loop_mouse(speed, -1)
    elif (right - left) > 25:
        loop_mouse(speed,1)


def loop_mouse(speed, direction):
    for i in range(speed):
        mouse.move(direction*2,0, absolute=False)
        time.sleep(0.01)

while True:
    s:bytes = ser.read(10000)
    if s:
        try:
            split = s.index(b',')
            left = int(s[:split])
            right = int(s[split+1:])
            print(left, right)
            move_mouse(left,right)
        except ValueError:
            pass