SUMMARY = "Qt informative app"
DESCRIPTION = "A simple Qt application that display information about car"
LICENSE = "MIT"

# The LIC_FILES_CHKSUM is the checksum of the license file that is included in the source code
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI:append = " \
    file://bluetooth.py \
    "

S = "${WORKDIR}"

do_install(){
    # Install the bluetooth.py file to the /usr/bin directory
    install -d ${D}${bindir}
    install -m 0755 bluetooth.py ${D}${bindir}
}
 