#!/bin/env sh

update_bat () { 
	# you might need to change the path depending on your device
	read -r bat_status </sys/class/power_supply/BAT0/status
	read -r bat_capacity </sys/class/power_supply/BAT0/capacity
	if [ "$bat_status" = "Charging" ]; then
		bat_status="🔌"
	else
		bat_status="🔋"
	fi
	bat="$bat_status $bat_capacity%"
  echo $bat
#  batterynotify
}
update_bat


