
#!/bin/bash

wallpaper_dir="$HOME/.config/wallpapers"
change_interval=300  # 5 minutes in seconds

while true; do
    # Get a random wallpaper from the directory
    random_wallpaper=$(ls "$wallpaper_dir" | shuf -n 1)

    # Set the wallpaper using feh
    feh --bg-scale "$wallpaper_dir/$random_wallpaper"

    # Sleep for the specified interval
    sleep "$change_interval"
done
