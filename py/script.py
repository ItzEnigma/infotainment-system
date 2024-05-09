import cv2
import time
import threading
import subprocess

face_classifier = cv2.CascadeClassifier(
    cv2.data.haarcascades + "haarcascade_frontalface_default.xml"
)

video_capture = cv2.VideoCapture(0)

imagePath = 'cat.jpg'

img = cv2.imread(imagePath)
gray_image = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

def my_timer_callback():
        result = subprocess.run(command, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, encoding='utf-8')

def detect_bounding_box(vid):
    gray_image = cv2.cvtColor(vid, cv2.COLOR_BGR2GRAY)
    faces = face_classifier.detectMultiScale(gray_image, 1.1, 5, minSize=(40, 40))
    for (x, y, w, h) in faces:
        cv2.rectangle(vid, (x, y), (x + w, y + h), (0, 255, 0), 4)
    return faces

timeout = threading.Timer(3, my_timer_callback, )
while True:

    result, video_frame = video_capture.read()  # read frames from the video
    if result is False:
        break  # terminate the loop if the frame is not read successfully

    faces = detect_bounding_box(
        video_frame
    )  # apply the function we created to the video frame

    #cv2.imshow(
     #   "My Face Detection Project", video_frame
    #)  # display the processed frame in a window named "My Face Detection Project"
    time.sleep(1)
    
    
    # Check if any faces are found
    if len(faces) > 0:
        # Cancel the timeout
        timeout.cancel()
    else:
        # Start the timeout if it's not already running
        if not timeout.is_alive():
            timeout = threading.Timer(3, my_timer_callback)
            timeout.start()
            
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

video_capture.release()
cv2.destroyAllWindows()


