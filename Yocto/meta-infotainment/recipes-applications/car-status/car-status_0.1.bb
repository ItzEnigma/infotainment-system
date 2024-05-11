SUMMARY = "Qt car status app"
DESCRIPTION = "A simple Qt application to display engine's temperature"
LICENSE = "MIT"

# The LIC_FILES_CHKSUM is the checksum of the license file that is included in the source code
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI:append = " \
    file://carstatus_app.cpp \
    file://carstatus_app.h \
    file://carStatus_App.pro \
    file://main.cpp \
    file://carstatus_app.ui \ 
    file://resources.qrc \
    file://img \
    "


S = "${WORKDIR}"

FILES:${PN} = " \
      /opt/carStatus_App/bin/carStatus_App \
      /usr/bin/carStatus_App \    
      "

DEPENDS += " qtbase"

do_install:append () {
    install -d ${D}${bindir}
    install -m 0755 carStatus_App ${D}${bindir}/
}

inherit qt6-qmake
