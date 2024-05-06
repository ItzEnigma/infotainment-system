# Description and Maintainer
SUMMARY = "Network Service Recipe by Enigma"
DESCRIPTION = "Service to give static ip for network interface"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"



SRC_URI = "file://10-static.network"

# In a recipe or bbappend:
do_install:append() {
    install -d ${D}/etc/systemd/network/
    install -m 0644 ${WORKDIR}/10-static.network ${D}/etc/systemd/network/
}

FILES_${PN} += "/etc/systemd/network/10-static.network"
