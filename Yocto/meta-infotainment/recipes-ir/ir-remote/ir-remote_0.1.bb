SUMMARY = "Recipe to include IR remote configurations"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI:append = " \
    file://lircd.conf \
    file://keyboard-ir-binding.py \
    file://keyboard-ir.service \
    "
S = "${WORKDIR}"

SYSTEMD_SERVICE:${PN} = " keyboard-ir.service"
REQUIRED_DISTRO_FEATURES= "systemd"

inherit systemd

SYSTEMD_AUTO_ENABLE = "enable"


FILES:${PN} = " \
    /lib \
    /lib/systemd \
    /lib/systemd/system \
    /lib/systemd/system/keyboard-ir.service \
    /etc \
    /usr \
    /etc/lirc \
    /etc/lirc/lircd.conf \
    /usr/bin \
    /usr/bin/keyboard-ir-binding.py \
"

do_install(){
    # Install the lircd.conf file to the /etc/lirc directory
    install -d ${D}${sysconfdir}/lirc
    install -m 0644 lircd.conf ${D}${sysconfdir}/lirc

    # Install the keyboard-ir-binding.py file to the /usr/bin directory
    install -d ${D}${bindir}
    install -m 0755 keyboard-ir-binding.py ${D}${bindir}

    # Install the keyboard-ir.service file to the /lib/systemd/system directory
    install -d ${D}${systemd_system_unitdir}
    install -m 0644 ${WORKDIR}/keyboard-ir.service ${D}${systemd_system_unitdir}/
}
