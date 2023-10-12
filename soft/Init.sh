sudo apt-get install libpcap-dev #install the libpcap-dev library

ip -o addr show | awk '/inet/ {print $2, $3, $4}' #get info about the network card