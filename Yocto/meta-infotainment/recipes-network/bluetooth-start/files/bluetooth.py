import os
import subprocess
import time
import keyboard

def start_pulseaudio():
    try:
        subprocess.run(['pulseaudio', '--start'], check=True)
        print("PulseAudio started successfully!")
        return True
    except subprocess.CalledProcessError as e:
        print(f"Failed to start PulseAudio: {e}")
        return False

def unblock_bluetooth():
    try:
        # Switch to root user
        
        os.system('su')
        #keyboard.press_and_release('enter')                            
        print("OKKKKKKK")                                                      
        subprocess.run(['rfkill', 'unblock', 'bluetooth'], check=True)   
        print("OKKK")
        print("Bluetooth unblocked successfully!")                       
        return True
    except Exception as e:
        print(f"Failed to unblock Bluetooth: {e}")
        return False
    finally:
        # Switch back to weston user
        try:
            os.system('su weston')
        except Exception as e:
            print(f"Failed to switch back to weston user: {e}")

def turn_on_bluetooth():
    try:
        subprocess.run(['connmanctl', 'enable', 'bluetooth'], check=True)
        print("Bluetooth turned on successfully!")
        return True
    except subprocess.CalledProcessError as e:
        print(f"Failed to turn on Bluetooth: {e}")
        return False

def pair_with_headphones(device_mac):
    try:
        subprocess.run(['bluetoothctl', 'scan', 'on'], timeout=15)
        #subprocess.run(['bluetoothctl', 'pair', device_mac], check=True)
        #print("Paired successfully!")
        return True
    except subprocess.CalledProcessError as e:
        print(f"Failed to pair: {e}")
        return False
    except subprocess.TimeoutExpired:
        subprocess.run(['bluetoothctl', 'pair', device_mac], check=True)
        return True	
def connect_to_headphones(device_mac):
    try:
        subprocess.run(['bluetoothctl', 'connect', device_mac], check=True)
        print("Connected successfully!")
        return True
    except subprocess.CalledProcessError as e:
        print(f"Failed to connect: {e}")
        return False

if __name__ == "__main__":
    # Start PulseAudio
    if not start_pulseaudio():
        print("Failed to start PulseAudio. Exiting...")
        exit()

    headphones_mac = "78:15:2D:0C:3A:8D"  # Replace with your headphones' MAC address
    #headphones_mac = "64:72:D8:DA:AF:27"
    #print("OKKKKKK")
    # Unblock Bluetooth
    #if not unblock_bluetooth():
    #    print("Failed to unblock Bluetooth. Exiting...")
    #    exit()

    # Turn on Bluetooth
    #if not turn_on_bluetooth():
    #     print("Failed to turn on Bluetooth. Exiting...")
    #     exit()

    # Pair with headphones
    if not pair_with_headphones(headphones_mac):
         print("Failed to pair with headphones. Exiting...")
         exit()

    # Connect to headphones
    connect_attempt = 0
    max_attempts = 3
    while connect_attempt < max_attempts:
        print(f"Attempting to connect to {headphones_mac} (attempt {connect_attempt + 1} of {max_attempts})...")
        if connect_to_headphones(headphones_mac):
            break
        connect_attempt += 1
        time.sleep(2)  # Wait for a few seconds before retrying
    else:
        print("Failed to connect after multiple attempts. Exiting...")

