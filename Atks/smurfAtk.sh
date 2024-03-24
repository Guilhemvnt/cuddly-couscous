#!/bin/bash

# check nb arguments
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <source_ip> <destination_ip>"
    exit 1
fi

# get ip from arguments
source_ip="$1"
destination_ip="$2"

# set a limits to nb packets send
packet_count=500
timeout 1 hping3 -1 --flood -c "$packet_count" -a "$source_ip" "$destination_ip"
