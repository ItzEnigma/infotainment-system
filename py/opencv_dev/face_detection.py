import cv2
import time
import sys

# face_classifier = cv2.CascadeClassifier(
#    "haarcascade_frontalface_default.xml"
# )



# imagePath = 'cat.jpg'

# img = cv2.imread(imagePath)
# gray_image = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

def detect_bounding_box(vid):
    gray_image = cv2.cvtColor(vid, cv2.COLOR_BGR2GRAY)
    faces = face_classifier.detectMultiScale(gray_image, 1.1, 5, minSize=(40, 40))
    for (x, y, w, h) in faces:
        cv2.rectangle(vid, (x, y), (x + w, y + h), (0, 255, 0), 4)
    return faces

while True:
    i = 0 
    video_capture = cv2.VideoCapture(0)
    result, video_frame = video_capture.read()  # read frames from the video
    while result is False:
        i = i + 1
        video_capture = cv2.VideoCapture(0)
        result, video_frame = video_capture.read()  # read frames from the video
        print(result) # print
        if i == 40 :
            print("can't Assign Camera")
            sys.exit(0) 
            break  # terminate the loop if the frame is not read successfully

    # faces = detect_bounding_box(
    #     video_frame
    # )  # apply the function we created to the video frame

    cv2.imshow(
       "My Face Detection Project", video_frame
    )  # display the processed frame in a window named "My Face Detection Project"
    time.sleep(1)
    # # Check if any faces are found
    # if len(faces) > 0:
    #     print("Face found")
    # else:
    #     print("No faces found")
    # if cv2.waitKey(1) & 0xFF == ord("q"):
    #     break

video_capture.release()
cv2.destroyAllWindows()