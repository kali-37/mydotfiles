#!/bin/sh


'
# will execute this by xinit . 
userresources=$HOME/.Xresources
usermodmap=$HOME/.Xmodmap sysresources=/etc/X11/xinit/.Xresources
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
'
echo ".xinitrc     --- vitra \n" >> ~/execution_order.log
#mounter & # mount hdd ext4 wala that is in sdb1 ..
nohup xmodmap .Xkeymap & 
nohup xbindkeys -f ~/.xbindkeysrc  && xbindkeys &
#nohup picom -b &
#nohup /usr/bin/emacs --daemon &
yay -Qq | awk -F/ '{print $1}' > ~/.installed_packages.txt
DISPLAY=":0" picom -b

#nohup dunst &
nohup sleep 2.3 && mine_monitor &
exec dwm
