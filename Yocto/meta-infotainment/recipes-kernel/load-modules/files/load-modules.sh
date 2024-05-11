#!/bin/bash

# Load first driver using insmod
echo "Loading GPIO driver using insmod..."
insmod /lib/modules/5.15.92-v8/extra/gpio_driver.ko.xz

# Check if the first driver loaded successfully
if [ $? -eq 0 ]; then
    echo "GPIO driver loaded successfully."
    echo "Loading w1-gpio driver using modprobe..."
    modprobe modprobe w1-gpio
    # Check if the second driver loaded successfully
    if [ $? -eq 0 ]; then
        echo "Second driver loaded successfully."
    else
        echo "Failed to load second driver."
    fi

    echo "Loading w1-therm driver using modprobe..."
    modprobe w1-therm
    # Check if the third driver loaded successfully
    if [ $? -eq 0 ]; then
        echo "Third driver loaded successfully."
        /usr/bin/GPIO_ButtonLED &
    else
        echo "Failed to load third driver."
    fi
else
    echo "Failed to load first driver."
fi
