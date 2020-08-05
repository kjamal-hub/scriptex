# Setup for TP-Link wn722n v2 for Pen-Testing

TP-link wn722n has realtek rtl8188eu drivers that are not compatible for monitoring mode without some changes.

1. First of all follow the instructions on the main.txt file.
    i.  Do it as root user, see sudo-su-1.png
    ii. Do an update after that using "apt-get update && apt-get upgrade -y" 

2. Add the line in NetworkManager.conf 
    i.  Open NetworkManager.conf by the command "nano /etc/NetworkManager/NetworkManager.conf"
    ii. Add lines from "network conf.txt" 
    iii.Also change 'ifupdown' false to true.
    iv. See "Net-Manager.png"
   
3. See whether your are in 'Monitor' mode or not.
    i.  type in "iwconfig"
    ii. yours should look like 'wlan-monitor-1.png'.

4.  See whether your adapter is working in in monitor mode or not
    i.  Type commands given in "airmon kill.png" then "airo-dump.png"
    ii. You will then be able to see interfaces around you linke "airo-dump-1.png"
    
5.  
      

