# Yocto GPIO Driver Recipes and Source Code

This directory contains the recipes and source code for the GPIO kernel driver module and the GPIO Application for controlling LED by a button.

---

## GPIO Kernel Driver Module

Contains two necessary recipes for the GPIO kernel driver module:

- `gpio-driver_0.1- The recipe for the GPIO kernel driver module.
- `linux-yocto...` - The recipe for the Linux kernel.

To modify or add a new kernel module ... you have to make a corresponding recipe:

1. **Modify/Add** the kernel module recipe _(Add `SRC_URI` files and `RPROVIDES_${PN}` with your to be generated module name)\_.
2. **Modify/Add** the Makefile in the kernel module source code to include the new module.
3. **Bitbake** the kernel module recipe to generate the kernel module and check if there are errors !

The kernel module source code allocates GPIO pins _(Input & Output)_ based on their structure ... and their corresponding ID corresponds to the GPIOx _(Pin Number)_.

---

## GPIO Application

Contains the recipe for the GPIO Application for controlling LED by a button which is implemented in C++.

> :exclamation: `${CXX}` is used to compile the C++ source code.

If you want to add a new application, you have to make a corresponding recipe:

1. **Modify/Add** the application recipe _(Add `SRC_URI` files and `do_compile` & `do_install` tasks)_.
2. **Bitbake** the application recipe to generate the application and check if there are errors !

---

## Network Ethernet Static Configuration

`addnetwork` recipe is used to configure the network interface with a static IP address ... by adding the **`10-static.network`** file to the `/etc/systemd/network/` directory.

---

> :white_check_mark: Don't forget to add the layer to the `bblayers.conf` file and the recipes to the `local.conf` file with `IMAGE_INSTALL_append` variable.

## `Devtool` Deployment

You can use `devtool` to build the source code of the kernel module and the application to your workspace ... and then **deploy** the output to your target _(Raspberry Pi)_ without the need of reflashing the image onto the SD card.

**Steps:**

1. `devtool modify {recipe-name}` --> devtool modify gpio-driver
2. `devtool build {recipe-name}` --> devtool build gpio-driver
3. `devtool deploy {recipe-name} root@{ip-address}` --> devtool deploy gpio-driver root@192.168.2.200
4. `ssh root@{ip-address}` --> ssh root@192.168.2.200
5. `insmod` /lib/modules/4.19.94-yocto-standard/kernel/drivers/gpio/gpio-driver.ko
6. `GPIO_ButtonLED` --> To run the application
7. `rmmod` gpio-driver --> To remove the module
8. `poweroff` --> To shutdown the Raspberry Pi
9. `devtool finish {recipe-name} {layer-name}` --> devtool finish gpio-driver meta-infotainment

- `devtool modify` creates & **moves** the source code from your layer recipe into the **workspace directory sources**.
- `devtool build` builds the source code in the **workspace directory**.
- `devtool deploy` deploys the output to the target.
- `devtool finish` moves the source code back to the layer recipe **(Very helpful if you were updating the source code)**.
