import cv2

# Load the image
imagePath = 'cat.jpg'
img = cv2.imread(imagePath)

# Convert the image to grayscale
gray_image = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Initialize the face cascade classifier
face_classifier = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Detect faces
faces = face_classifier.detectMultiScale(
    gray_image,
    scaleFactor=1.1,
    minNeighbors=5,
    minSize=(40, 40)
)

# Check if any faces are found
if len(faces) > 0:
    print("Face found")
else:
    print("No faces found")
