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
  PATH_TO/meta-raspberrypi \
  PATH_TO/meta-infotainment \
  "
```

1- Use the conf directory as is, and copy the contents of the conf directory to the build directory.
2- Use the meta-infotainment layer to include weston-init patch and launcher recipe
3- Build using the `core-image-weston` image