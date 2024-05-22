DESCRIPTION = "GPIO Control LED by Button press application Recipe"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://GPIO_ButtonLED.cpp"

S = "${WORKDIR}"

do_compile() {
	${CXX} ${LDFLAGS} GPIO_ButtonLED.cpp -o GPIO_ButtonLED
}

do_install() {
	install -d ${D}${bindir}
	install -m 0755 GPIO_ButtonLED ${D}${bindir}
}
