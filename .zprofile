#
# ~/.bash_profile
#

echo "executing .zprofile \n" >> ~/execution_order.log

[[ -f ~/.zshrc ]] && . ~/.zshrc
echo "executing .zprofile vitra \n" >> ~/execution_order.log


if [[ "$(tty)" = "/dev/tty1" ]]; then 
  echo " Hyprland loaded \n " >> ~/execution_order.log
  Hyprland
elif [[ "$(tty)" = "/dev/tty2" ]]; then 
  echo "______________________________\n " >> ~/execution_order.log
  exec startx  >> ~/execution_order.log
else
  echo "NOt launching start x cause it's not tty1 " >> ~/execution_order.log 
fi
