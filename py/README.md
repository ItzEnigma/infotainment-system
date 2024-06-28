# Python Scripts

with the intent of exploiting Linux features on Embedded target, we used a high-level language with support for reach frameworks with outstanding technologies, we decided to use `python` and its packages `openCV`, `paho-mqtt`, and `sub-process`. 

The following features are implemented by the included Python scripts:

1. [AI Locker with openCV](#1-ai-locker-with-opencv)
2. [IoT](#2-iot)
    * [GPS](#21-gps)
    * [DIO Reciever](#22-dio-reciever)
    * [Temprature Sensor Broadcast](#23-temperature-sensor-broadcast)
    

## 1. AI Locker with openCV
To optimize power usage in the infotainment system, a lock screen will be launched when no person is detected in front of the system.

The following flow chart illustrates the script's process:


![flow chart](https://i.ibb.co/N9Y1dYw/flochart1.png)

Face detection is performed using the Haar Cascade filter, which is included in the OpenCV library. The screen locker is launched by executing bash commands using the subprocess library.

## 2. IoT

Since the image supports Python, a Paho MQTT client is used to connect to the MQTT broker ([mqtt-dashboard.com](https://mqtt-dashboard.com)) and publish/subscribe to specific topics.

The IoT is integrated with a Node-Red application on the client side that provides a dashboard for the consumer to display the readings.

Every script that publishes/subscribes to the IoT broker follows these steps:

1. Initialize the connection to the broker:
    ```python
    broker = 'mqtt-dashboard.com'
    port = 1883
    ```

2. Connect to a specific topic:
    ```python
    # gps_iot.py
    topic = "/sudoteam/infotainment/gps"
    ```

3. Acquire a random client ID:
    ```python
    client_id = f'publish-{random.randint(0, 1000)}'
    ```

4. Connect to the broker with the acquired ID and return a `client` object:
    ```python
    def connect_mqtt():
        client = mqtt_client.Client(client_id)
        client.connect(broker, port)
        return client
    ```

5. Start listening:
    ```python
    client.loop_start()
    ```

6. Publish or subscribe to the specified topic:
    ```python
    # gps_iot.py
    body = f'"lat" : {lat}, "lon" : {lng}, "name" : "rpi", "command": {{"panit" : true, "zoom" : 18}}'

    publish(client, body)
    ```

7. Close the connection upon exiting the application:
    ```python
    client.loop_stop()
    ```

These steps outline the process with code snippets. The complete code is available in the Python scripts.

The following sections demonstrate how each component works and how it integrates with the IoT.

### 2.1 GPS

With the `NEO-6M GPS module`, the system retrieves its geographic position. The GPS Module uses UART to send GPS data in NMEA format. Apart from using the UART port, the GPS Module is connected to the RPi via USB, and its data is received in the file `/dev/ttyUSB0`.

The GPS IoT script decodes the NMEA readings and checks if they contain valid data. If valid data is detected, it publishes the readings to the broker, which are then received by the Node-Red client application.

Since the GPS module is not guaranteed to read valid data every time, the script checks for available data. The following procedures are implemented in the GPS script (after IoT initialization):

1. Open the serial file to read from:
    ```python
    ser = serial.Serial ("/dev/ttyUSB0")  
    ```
2. Start an infinite loop to continuously read from the device file and surround it with a try-catch block:
    ```python
    try:
        while True:
                pass
    except KeyboardInterrupt:
            ser.close()     
            sys.exit(0)
    ```
3. Check if GPS receives a signal from the satellites:
    ```python
    try:
        while True:
            received_data = (str)(ser.readline().decode())   
            GPGGA_data_available = received_data.find(gpgga_info)        
            if (GPGGA_data_available>=0):
                #avaliable
    ```

4. Decode the received data and publish it:
    ```python
    if (GPGGA_data_available>=0):
                GPGGA_buffer = received_data.split("$GPGGA,",1)[1]  
                NMEA_buff = (GPGGA_buffer.split(','))               #store comma separated data in buffer
                try :
                    lat, lng = GPS_Info(NMEA_buff)                                         
                    body = f'"lat" : {lat}, "lon" : {lng}, "name" : "rpi", "command":' +  '{ "panit" : true, "zoom" : 18 } '
                    publish(client, body )             
                except:
                    print("can't decode")
                    pass
    ```

### 2.2 DIO Reciever

This script exploits and provides a proof of concept for implementing a receiving side between the device, the broker, and the Node-Red client dashboard.

The client listens to the `/sudoteam/infotainment/dio` topic and writes to the `/dev/dio1` file in case of a new message.



```python
def subscribe(client: mqtt_client):
    def on_message(client, userdata, msg):
        data = msg.payload.decode()
        result = subprocess.check_output(f"echo {data} > /dev/dio1", shell=True, executable="/bin/bash", stderr=subprocess.STDOUT)
        
    client.subscribe("/sudoteam/infotainment/dio")
    client.on_message = on_message
```

### 2.3 Temperature Sensor Broadcast

This script exploits and provides a proof of concept for implementing a transmitter side between the device, the broker, and the Node-Red client dashboard.

The device listens to the temperature sensor device file `/sys/devices/w1_bus_master1/28-3de1e380281d/temperature`.

The file reads the temperature * 100. For example, if a temperature is `23.24`, it will be represented in the file as `2324`. Hence, the script formats the temperature reading accordingly before sending it.

1. Open the temperature sensor device file in read mode:
    ```python
    with open("/sys/devices/w1_bus_master1/28-3de1e380281d/temperature", "r") as file1:
    ```

2. Read the file and convert it to an integer:
    ```python
        tmp = file1.read()
        tmp = int(tmp)
    ```
3. Divide the reading by 100:
    ```python
        tmp = tmp / 100
    ```
4. Publish the reading:
    ```python
        publish(client, tmp)
    ```
5. Close the file:
    ```python
        file1.close() 
    ```

The complete function:
```python
def temperature_broadcast(client):
    try:
        while True:
            time.sleep(3)
            with open("/sys/devices/w1_bus_master1/28-3de1e380281d/temperature", "r") as file1:
                tmp = file1.read()
                tmp = int(tmp)
                tmp = tmp / 100
                publish(client, tmp)
                file1.close()  
    except KeyboardInterrupt:
        sys.exit(0)

```