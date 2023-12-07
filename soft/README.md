#Pentesting Network

## Understand spoofing ip
- IP spoofing is a technique in which an attacker sends IP packets from a false (or "spoofed") source address in order to deceive the recipient about the origin of the message. This can be done for hiding the true source of an attack, bypassing access controls, or launching a denial-of-service (DoS) attack.

## Decoy Scanning Attempts
-When analyzing network traffic, be vigilant for the following signs of decoy scanning attempts:

- Look for multiple instances of fragmented IP protocol in the Info field, as this could indicate an attack.
- Check TCP traffic from legitimate source addresses.
- Watch for connections initiated by one host and taken over by another, as attackers may reveal their true source address.

## DauthFrames
- Use `g++ -o rst_packet rst_packet.cpp <ipSrc> <ipDst>` (use valid IP addresses for `ipSrc` and `ipDst`)
- Check if reset packets are detected by the sniffer (RST Flag: 1 and nothing in other falgs)

## SMURF Attack
- SMURF attacks involve sending ICMP requests to live hosts with a spoofed victim host address. To detect SMURF attacks:

- Examine ICMP protocol traffic.
- If you observe many different hosts pinging a single host, it may indicate a SMURF attack.
- use smurfAtk.sh

## LAND Attack
- LAND attacks involve an attacker spoofing their source IP to match the destination. These attacks rely on sheer traffic volume and port re-use. Be cautious of this type of DOS attack.
- user LANDAtk.sh

## TTL
- Check if an abnormal number of packets have a low Time to Live; it may indicate that an attack is ongoing in your network. This is often used by attackers to avoid firewall detection.

## TCP Handshake Abnormalities

- Excessive SYN flags may indicate nmap scanning or other suspicious activity during the TCP handshake.
- When any attacks are try it will often trigger this attack (ex with LAND and SMURF) indeed the bash scipts didn't take care of TCP flags.


# Understand IP Address 
## 224.0.0.251

The IP address 224.0.0.251 is a multicast IP address reserved for the use of the Zeroconf (Zero Configuration Networking) service discovery protocol, also known as mDNS (multicast DNS). mDNS allows devices on a local network to discover and connect to each other without prior configuration. This IP address is used for the resolution of local domain names without the need for a central DNS server.

In other words, when a device on the local network is searching for other devices or services, it can broadcast multicast queries to the IP address 224.0.0.251 to discover the services available on the network without requiring a traditional DNS infrastructure. This is commonly used in home and local networks to facilitate the automatic discovery of devices and services without manual configuration.

## Reserved IP Addresses
There several ranges of IP addresses reserved for specific purposes, such as particular services, specific communication protocols, or reserved uses for specific purposes. Here are some examples:

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

**Disclaimer:** This repository is for educational purposes only. Use this information responsibly and within legal boundaries.
