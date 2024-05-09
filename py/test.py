import cv2
import time

# face_classifier = cv2.CascadeClassifier(
#    "haarcascade_frontalface_default.xml"
# )

video_capture = cv2.VideoCapture(0)

# imagePath = 'cat.jpg'

# img = cv2.imread(imagePath)
# gray_image = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)



while True:

    result, video_frame = video_capture.read()  # read frames from the video
    if result is False:
        break  # terminate the loop if the frame is not read successfully


    cv2.imshow(
       "My Face Detection Project", video_frame
    )  # display the processed frame in a window named "My Face Detection Project"
    time.sleep(1)
    # Check if any faces are found
    
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

video_capture.release()
cv2.destroyAllWindows()