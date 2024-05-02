# Use the patch file in the files directory to patch the source code 
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI:append = " file://weston-ini-autolaunch.patch"