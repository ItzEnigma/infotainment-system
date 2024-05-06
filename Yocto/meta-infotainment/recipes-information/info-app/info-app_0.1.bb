SUMMARY = "Qt informative app"
DESCRIPTION = "A simple Qt application that display information about car"
LICENSE = "MIT"

# The LIC_FILES_CHKSUM is the checksum of the license file that is included in the source code
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI:append = " \
    file://informative_app.cpp \
    file://informative_app.h \
    file://Informative_APP.pro \
    file://main.cpp \
    file://informative_app.ui \   
    "

 
S = "${WORKDIR}"

FILES:${PN} = " \
     /opt/Informative_APP/bin/Informative_APP \
     /usr/bin/Informative_APP \    
    "

DEPENDS += " qtbase"

do_install:append () {
    install -d ${D}${bindir}
    install -m 0755 Informative_APP ${D}${bindir}/
}

inherit qt6-qmake
