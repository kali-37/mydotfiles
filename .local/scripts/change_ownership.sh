#!/bin/bash

chown kali_37:kali_37 /sys/class/backlight/intel_backlight/brightness
chown kali_37:kali_37 /sys/class/backlight/intel_backlight/actual_brightness
chmod +rwx /sys/class/backlight/intel_backlight/actual_brightness
chmod +rwx /sys/class/backlight/intel_backlight/brightness
