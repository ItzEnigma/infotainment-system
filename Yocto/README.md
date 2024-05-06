# Initial Steps

> Make sure you are using Kirkstone branch and having the following layers in your `bblayers.conf` and installed:
```
BBLAYERS ?= " \
  PATH_TO/poky/meta \
  PATH_TO/poky/meta-poky \
  PATH_TO/poky/meta-yocto-bsp \
  PATH_TO/meta-openembedded/meta-oe \
  PATH_TO/meta-openembedded/meta-python \
  PATH_TO/meta-openembedded/meta-networking \
  PATH_TO/meta-openembedded/meta-multimedia
  PATH_TO/meta-raspberrypi \
  PATH_TO/meta-infotainment \
  "
```

1. Use the conf directory as is (Change downloads directory), and copy the contents of the conf directory to the build directory.
2. Use the meta-infotainment layer to include weston-init patch and launcher recipe
3. Build using the `core-image-weston` image


---

## This update contains:

1. Informative app included with Qt support
2. Launcher recipe is changed to include a pre configured one 
3. Integrated GPIO, IR, static ethernet ip
4. command line Media player called mpv 
