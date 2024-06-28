# python 3.11

import random
import subprocess 
from paho.mqtt import client as mqtt_client


broker = 'mqtt-dashboard.com'
port = 1883
topic = "/sudoteam/infotainment/dio"

# Generate a Client ID with the publish prefix.
client_id = f'publish-{random.randint(0, 1000)}'


def connect_mqtt() -> mqtt_client:
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
        else:
            print("Failed to connect, return code %d\n", rc)

    client = mqtt_client.Client(client_id)
    client.on_connect = on_connect
    client.connect(broker, port)
    return client


def subscribe(client: mqtt_client):
    def on_message(client, userdata, msg):
        data = msg.payload.decode()
        result = subprocess.check_output(f"echo {data} > /dev/dio1", shell = True, executable = "/bin/bash", stderr = subprocess.STDOUT)
        
    client.subscribe(topic)
    client.on_message = on_message


def run():
    client = connect_mqtt()
    subscribe(client)
    client.loop_forever()


if __name__ == '__main__':
    run()