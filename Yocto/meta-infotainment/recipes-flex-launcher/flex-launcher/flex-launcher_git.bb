# Recipe created by recipetool
# This is the basis of a recipe and may need further editing in order to be fully functional.
# (Feel free to remove these comments when editing.)

# WARNING: the following LICENSE and LIC_FILES_CHKSUM values are best guesses - it is
# your responsibility to verify that the values are complete and correct.
#
# The following license files were not able to be identified and are
# represented as "Unknown" below, you will need to check them yourself:
#   UNLICENSE
LICENSE = "Unknown"
LIC_FILES_CHKSUM = "file://UNLICENSE;md5=21ef108f5a4f7b4ef7f0ddbb3c6a6492"

SRC_URI = " \
	git://github.com/complexlogic/flex-launcher;protocol=https;branch=master \
	file://config.ini \	
	file://assets \
	"

# Modify these as desired
PV = "1.0+git${SRCPV}"
SRCREV = "b9a6761676abc9b3f43164909f1610447203f19b"

S = "${WORKDIR}/git"
INSANE_SKIP_${PN} = "ldflags"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_PACKAGE_STRIP = "1"
# NOTE: unable to map the following CMake package dependencies: SDL2_ttf sdl2_image
# NOTE: the following library dependencies are unknown, ignoring: REQUIRED getopt
#       (this is based on recipes that have previously been built and packaged)
DEPENDS  = "libsdl2 libsdl2-image libsdl2-ttf"

inherit cmake pkgconfig

# Specify any options you want to pass to cmake using EXTRA_OECMAKE:
EXTRA_OECMAKE = "-DCMAKE_BUILD_TYPE=Release"

do_configure(){
	mkdir -p ${S}/build
	cmake ${S} -B${S}/build
}

do_compile(){
	oe_runmake -C ${S}/build
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/build/flex-launcher ${D}${bindir}
	install -m 0755 ${WORKDIR}/config.ini ${D}${bindir}

	install -d ${D}${bindir}/assets/fonts
	install -m 0755 ${WORKDIR}/assets/fonts/* ${D}${bindir}/assets/fonts

	install -d ${D}${bindir}/assets/icons
	install -m 0755 ${WORKDIR}/assets/icons/* ${D}${bindir}/assets/icons
}

