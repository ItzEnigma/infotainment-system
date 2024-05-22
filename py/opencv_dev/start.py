import subprocess
import time
import threading


def my_timer_callback():
        result = subprocess.run("weston-terminal", shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, encoding='utf-8')
        print("Callback")
        
timeout = threading.Timer(10, my_timer_callback, )
while True:

    time.sleep(1)    
    if not timeout.is_alive():
            timeout = threading.Timer(3, my_timer_callback)
            timeout.start()
            



