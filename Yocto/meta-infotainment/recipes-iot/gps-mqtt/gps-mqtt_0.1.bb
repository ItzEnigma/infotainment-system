SUMMARY = "Recipe to include IR remote configurations"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI:append = " \
    file://gps_iot.py \
    "
S = "${WORKDIR}"

do_install(){
    # Install the gps_iot.py file to the /usr/bin directory
    install -d ${D}${bindir}
    install -m 0755 gps_iot.py ${D}${bindir}
}
