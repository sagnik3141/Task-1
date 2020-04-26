import serial
import pyautogui
ser=serial.Serial('com3',9600)
while 1:
    k=ser.read(8)
    cursor=k[:6]
    click=k[6:]
    x=cursor[:3]
    y=cursor[3:]
    l=click[0]
    r=click[1]
    xcor=int(x.decode('utf-8'))
    ycor=int(y.decode('utf-8'))
    pyautogui.moveTo(xcor,ycor)
    if l==49:
        pyautogui.click(clicks=2)
    elif r==49:
        pyautogui.click(button='right', clicks=2)