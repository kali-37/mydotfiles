#!/bin/env sh



update_backlight () { 
first="🌔 "
second="💡"
third="🔆"

function condition() {
    percentage=$1
    if (( $(echo "$percentage < 33" ) )); then
        backlight="$first"
    elif (( $(echo "$percentage < 66" ) )); then
        backlight="$second"
    else
        backlight="$third"
    fi
    echo $backlight
}

# You might need to change the path depending on your device
read -r actual_brightness </sys/class/backlight/intel_backlight/actual_brightness
read -r max_brightness </sys/class/backlight/intel_backlight/max_brightness
percentage=$((actual_brightness * 100 / max_brightness))
condition "$percentage"
}
update_backlight
