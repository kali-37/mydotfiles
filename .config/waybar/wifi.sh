update_internet(){
# Show wifi 📶 and percent strength or 📡 if none.
# Show 🌐 if connected to ethernet or ❎ if none.
# Show 🔒 if a vpn connection is active

if grep -xq 'up' /sys/class/net/w*/operstate 2>/dev/null ; then
    wifiicon="$(awk '/^\s*w/ { print "📶", int($3 * 100 / 70) "% " }' /proc/net/wireless)"
elif grep -xq 'down' /sys/class/net/w*/operstate 2>/dev/null ; then
    grep -xq '0x1003' /sys/class/net/w*/flags && wifiicon="📡 " || wifiicon="❌ "
fi

if grep -xq 'up' /sys/class/net/e*/operstate 2>/dev/null ; then
    etherneticon="🌐"
elif grep -xq 'down' /sys/class/net/e*/operstate 2>/dev/null ; then
    etherneticon="❎"
fi

if grep -q 'tun' /sys/class/net/*/operstate 2>/dev/null ; then
    vpnicon="🔒"
fi

wifivalue=$(printf "%s%s%s\n" "$wifiicon" "$etherneticon" "$vpnicon")
echo $wifivalue
}

update_internet


