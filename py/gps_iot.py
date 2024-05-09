# python 3.11

import random
import time

from paho.mqtt import client as mqtt_client

import serial               #import serial pacakge
from time import sleep
import sys                  #import system package



broker = 'mqtt-dashboard.com'
port = 1883
topic = "topic/topics"
# Generate a Client ID with the publish prefix.
client_id = f'publish-{random.randint(0, 1000)}'
# username = 'emqx'
# password = 'public'

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


def publish(client, msg):
        
        result = client.publish(topic, msg)
        # result: [0, 1]
        status = result[0]
        if status == 0:
            print(f"Send `{msg}` to topic `{topic}`")
        else:
            print(f"Failed to send message to topic {topic}")



def GPS_Info():
    global NMEA_buff
    global lat_in_degrees
    global long_in_degrees
    nmea_time = []
    nmea_latitude = []
    nmea_longitude = []
    nmea_time = NMEA_buff[0]                    #extract time from GPGGA string
    nmea_latitude = NMEA_buff[1]                #extract latitude from GPGGA string
    nmea_longitude = NMEA_buff[3]               #extract longitude from GPGGA string
    
    #print("NMEA Time: ", nmea_time,'\n')
    #print ("NMEA Latitude:", nmea_latitude,"NMEA Longitude:", nmea_longitude,'\n')
    
    lat = float(nmea_latitude)                  #convert string into float for calculation
    longi = float(nmea_longitude)               #convertr string into float for calculation
    
    lat_in_degrees = convert_to_degrees(lat)    #get latitude in degree decimal format
    long_in_degrees = convert_to_degrees(longi) #get longitude in degree decimal format
    
#convert raw NMEA string into degree decimal format   
def convert_to_degrees(raw_value):
    decimal_value = raw_value/100.00
    degrees = int(decimal_value)
    mm_mmmm = (decimal_value - int(decimal_value))/0.6
    position = degrees + mm_mmmm
    position = "%.4f" %(position)
    return position
    

def listen_to_serial(client):
    gpgga_info = "$GPGGA,"
    try:
         ser = serial.Serial ("/dev/ttyS0")              #Open port with baud rate
    except:
        serial.Serial ("/dev/ttyS0").close()              #Open port with baud rate
        ser = serial.Serial ("/dev/ttyS0")              #Open port with baud rate
   
    GPGGA_buffer = 0
    NMEA_buff = 0
    lat_in_degrees = 0
    long_in_degrees = 0

    try:
        while True:
            try:
                received_data = (str)(ser.readline())   
                #read NMEA string received
                GPGGA_data_available = received_data.find(gpgga_info)   #check for NMEA GPGGA string                 
                if (GPGGA_data_available>0):
                    GPGGA_buffer = received_data.split("$GPGGA,",1)[1]  #store data coming after "$GPGGA," string 
                    NMEA_buff = (GPGGA_buffer.split(','))               #store comma separated data in buffer
                    try :
                    
                        nmea_time = []
                        nmea_latitude = []
                        nmea_longitude = []
                        nmea_time = NMEA_buff[0]                    #extract time from GPGGA string
                        nmea_latitude = NMEA_buff[1]                #extract latitude from GPGGA string
                        nmea_longitude = NMEA_buff[3]               #extract longitude from GPGGA string
        
                        lat = float(nmea_latitude)                  #convert string into float for calculation
                        longi = float(nmea_longitude)               #convertr string into float for calculation
        
                        lat_in_degrees = convert_to_degrees(lat)    #get latitude in degree decimal format
                        long_in_degrees = convert_to_degrees(longi) #get longitude in degree decimal format
                        publish(client,  f"{lat_in_degrees}, {long_in_degrees} ")
                        GPS_Info()                                          #get time, latitude, longitude
                        #publish(client,  "lat in degrees:" +  lat_in_degrees +" long in degree: "+ long_in_degrees)
                        #print("lat in degrees:", lat_in_degrees," long in degree: ", long_in_degrees, '\n')
                    except:
                        pass
            except :
                pass
                #ser.close()
                #ser = serial.Serial ("/dev/ttyS0")  
    except KeyboardInterrupt:
        ser.close()     
        #webbrowser.open(map_link)        #open current position information in google map
        sys.exit(0)


def run():
    client = connect_mqtt()
    client.loop_start()
    #publish(client)
    listen_to_serial(client)
    client.loop_stop()


if __name__ == '__main__':
    run()

