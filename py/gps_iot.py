# python 3.11

import random
from paho.mqtt import client as mqtt_client

import serial              
from time import sleep
import sys                



broker = 'mqtt-dashboard.com'
port = 1883
topic = "/sudoteam/infotainment/gps"
# Generate a Client ID with the publish prefix.
client_id = f'publish-{random.randint(0, 1000)}'


def connect_mqtt():
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
        else:
            print("Failed to connect, return code %d\n", rc)

    client = mqtt_client.Client(client_id)
    client.on_connect = on_connect
    client.connect(broker, port)
    return client


def publish(client, msg):
        
        result = client.publish(topic, msg)
        status = result[0]
        if status == 0:
            print(f"Send `{msg}` to topic `{topic}`")
        else:
            print(f"Failed to send message to topic {topic}")



def GPS_Info(NMEA_buff):

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
    return (lat_in_degrees, long_in_degrees)

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
   
    ser = serial.Serial ("/dev/ttyUSB0")  
    GPGGA_buffer = 0
    NMEA_buff = 0
    
    try:
       while True:
        received_data = (str)(ser.readline().decode())   
        #read NMEA string received
        GPGGA_data_available = received_data.find(gpgga_info)   #check for NMEA GPGGA string                 
        if (GPGGA_data_available>=0):
            GPGGA_buffer = received_data.split("$GPGGA,",1)[1]  #store data coming after "$GPGGA," string 
            NMEA_buff = (GPGGA_buffer.split(','))               #store comma separated data in buffer
            try :
                lat, lng = GPS_Info(NMEA_buff)                                          #get time, latitude, longitude
 
                #print("lat in degrees:", lat," long in degree: ", lng, '\n') in case of debugging
                body = f'"lat" : {lat}, "lon" : {lng}, "name" : "rpi", "command":' +  '{ "panit" : true, "zoom" : 18 } '
                publish(client, body )
                              
            except:
                print("can't decode")
                pass
    except KeyboardInterrupt:
        ser.close()     
        sys.exit(0)


def run():
    client = connect_mqtt()
    client.loop_start()
    #publish(client)
    listen_to_serial(client)
    client.loop_stop()


if __name__ == '__main__':
    run()

