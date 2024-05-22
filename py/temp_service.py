import serial               #import serial pacakge
import time 
import sys                  #import system package
import random
from paho.mqtt import client as mqtt_client
import subprocess


broker = 'mqtt-dashboard.com'
port = 1883
topic = "/sudoteam/infotainment/temperature"
# Generate a Client ID with the publish prefix.
client_id = f'publish-{random.randint(0, 1000)}'

#ser = serial.Serial ("/sys/devices/w1_bus_master1/28-3de1e380281d/temperature")  #/dev/ttyS0            #Open port with baud rate


def publish(client, msg):
    time.sleep(1)
    result = client.publish(topic, msg)
        # result: [0, 1]
    status = result[0]
    if status == 0:
            print(f"Send `{msg}` to topic `{topic}`")
    else:
            print(f"Failed to send message to topic {topic}")


def temprature_broadcast(client):
    try:
        while True:
            time.sleep(3)
            with open("/sys/devices/w1_bus_master1/28-3de1e380281d/temperature", "r") as file1:
                tmp = file1.read()
                tmp = int(tmp)
                tmp = tmp / 1000
                publish(client, tmp)
                file1.close()  # to change file access modes
            #received_data = (str)(ser.readline())   
        
    except KeyboardInterrupt:
        #ser.close()     
        #webbrowser.open(map_link)        #open current position information in google map
        sys.exit(0)


def connect_mqtt():
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
        else:
            print("Failed to connect, return code %d\n", rc)

    
    client = mqtt_client.Client(client_id)
    # client.username_pw_set(username, password)
    client.on_connect = on_connect
    client.connect(broker, port)
    return client

def run():
    client = connect_mqtt()
    client.loop_start()
    temprature_broadcast(client)
    #publish(client)
    client.loop_stop()


if __name__ == '__main__':
    run()
