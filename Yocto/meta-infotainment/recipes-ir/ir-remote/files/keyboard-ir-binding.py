import subprocess
import keyboard
import time

# Define the command to run irw
command = ["irw"]

# Start irw as a subprocess
process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

# Define dictionary to map remote keys to scripts
key_ir_map = {
    "KEY_UP": "up",
    "KEY_RIGHT": "right",
    "KEY_MUTE": "mute",
    "KEY_EXIT": "exit",
    "KEY_DOWN": "down",
    "KEY_LEFT": "left",    
    "KEY_ENTER": "enter",
    "KEY_REWIND": "backspace",
    "KEY_STOP": "super+k",
    # Add more key-script mappings as needed
}


# up, left , right, down


# Simulate pressing the 'a' key
# keyboard.press_and_release()
# time.sleep(0.5)  # Wait for 0.5 seconds
# keyboard.release('a')  # Release the 'a' key

try:
    # Continuously read the output of irw
    for line in iter(process.stdout.readline, b''):
        line = line.decode("utf-8").strip()
        # Split the line into tokens
        tokens = line.split()
        if len(tokens) >= 3:
            key = tokens[-2]  # Extract the key from the third token from the end
            if key in key_ir_map:
                keyboard_key = key_ir_map[key]
                keyboard.press_and_release(keyboard_key)
        else :
            continue
        time.sleep(0.2)
except KeyboardInterrupt:
    # Handle KeyboardInterrupt
    print("KeyboardInterrupt: Terminating the process...")
finally:
    # Ensure the subprocess is terminated
    process.terminate()
