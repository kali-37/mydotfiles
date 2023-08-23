#!/bin/sh

userresources=$HOME/.Xresources
usermodmap=$HOME/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap
# merge in defaults and keymaps

if [ -f $sysresources ]; then







    xrdb -merge $sysresources

fi

if [ -f $sysmodmap ]; then
    xmodmap $sysmodmap
fi

if [ -f "$userresources" ]; then







    xrdb -merge "$userresources"

fi

if [ -f "$usermodmap" ]; then
    xmodmap "$usermodmap"
fi

# start some nice programs

if [ -d /etc/X11/xinit/xinitrc.d ] ; then
 for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
  [ -x "$f" ] && . "$f"
 done
 unset f
fi

#mounter & # mount hdd ext4 wala that is in sdb1 ..
nohup xmodmap .Xkeymap & 
nohup xbindkeys -f ~/.xbindkeysrc  && xbindkeys &
nohup xrandr --output VGA-1 --left-of eDP-1  &
nohup /usr/bin/pipewire &
nohup /usr/bin/pipewire-pulse &
nohup /usr/bin/pipewire-media-session &
nohup picom -b &
nohup /usr/bin/emacs --daemon &

# remember to put all the stuffs before exec dwm , 
exec dwm 
