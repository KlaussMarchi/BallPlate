import serial
import pandas as pd
import time

arduino = serial.Serial('/dev/ttyUSB0', 9600, timeout=5)
allData = []
time.sleep(2)
arduino.write('1'.encode())


def getValue():
    global arduino

    try:
        return eval(arduino.readline().decode('utf-8'))
    except:
        print('erro')
        return None

while True:
    data = getValue()

    if data is None:
        continue
    
    print(data)
    allData.append(data)

    if data[0] > 5:
        break

df = pd.DataFrame(allData, columns=['time', 'theta', 'distance'])
df.to_csv('DataBase.csv', index=False)
