do_install:append() {
  rm -rf ${D}${sysconfdir}/lirc/lircd.conf
}