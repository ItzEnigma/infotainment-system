SUMMARY = "Custom Image based on core-image-weston with additional packages and custom recipes"
DESCRIPTION = "This image is based on core-image-weston and includes additional packages and custom recipes for the infotainment project."
LICENSE = "MIT"

IMAGE_FEATURES += "splash package-management ssh-server-dropbear hwcodecs weston"

inherit core-image

CORE_IMAGE_BASE_INSTALL += "gtk+3-demo"
CORE_IMAGE_BASE_INSTALL += "${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'weston-xwayland matchbox-terminal', '', d)}"

QB_MEM = "-m 512"

# Include additional packages and custom recipes
IMAGE_INSTALL:append = " \
    wayland weston bash flex-launcher \
    mpv connman-gnome qtwayland connman connman-client wireless-regdb-static \
    bluez5 wayland-protocols weston-init libsdl2 libsdl2-image libsdl2-ttf \
    python3-opencv python3-paho-mqtt python3-pyserial python3-pip sudo \
    blueman pulseaudio pulseaudio-server pulseaudio-misc \
    pulseaudio-module-dbus-protocol alsa-utils pi-bluetooth lirc \
    bluetooth-start gps-mqtt ir-remote car-status gpio-buttonled \
    gpio-driver addnetwork info-app \
    openssh openssl \
"
