import serial
import mouse

speed = 10
ser = serial.Serial('COM4', 9600, timeout=0.05)

def move_mouse(left:int,right:int):
    if (left-right) > 25:
        mouse.move(-1*speed,0, absolute=False)
    elif (right - left) > 25:
        mouse.move(speed,0, absolute=False)


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