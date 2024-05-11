SUMMARY = "Recipe to include IR remote configurations"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI:append = " \
    file://load-modules.service \
    file://load-modules.sh \
    "
S = "${WORKDIR}"

SYSTEMD_SERVICE:${PN} = " load-modules.service"
REQUIRED_DISTRO_FEATURES= "systemd"

inherit systemd

SYSTEMD_AUTO_ENABLE = "enable"


do_install(){
    install -d ${D}${bindir}
    install -m 0755 load-modules.sh ${D}${bindir}

    install -d ${D}${systemd_system_unitdir}
    install -m 0644 ${WORKDIR}/load-modules.service ${D}${systemd_system_unitdir}/
}
