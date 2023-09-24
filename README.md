# cuddly-couscous

Discover Wireshark sofware for Network Traffic Analysis :
  wget -O file.zip 'https://academy.hackthebox.com/storage/resources/pcap_files.zip' && mkdir tempdir && unzip file.zip -d tempdir && mkdir -p pcaps && mv tempdir/Intermediate_Network_Traffic_Analysis/* pcaps/ && rm -r tempdir file.zip
  I notice right away that an excessive amount of deauthentication frames were sent to one of our client devices.
  Adresse MAC = F8:14:FE:4D:E6:F1

For Filtering Deauthentication Frames in WireShark :

  (wlan.bssid == F8:14:FE:4D:E6:F1) and (wlan.fc.type == 0) && (wlan.fc.type_subtype == 12)
    
  (wlan.bssid == F8:14:FE:4D:E6:F1) --> the attacker on the wlan device

  (wlan.fc.type == 0) && (wlan.fc.type_subtype == 12) -> 0 to 12 is a default code use by "aireplay-ng" and "mdk4" , which are common attack tools for Deauthentication
  This code is found on the reason code of the request

======================================
Finding Decoy Scanning Attempts :
 
  - look at Info-> Fragmented IP protocol if there is multiple time this it must be an attack
  - Check the TCP traffic from the legitimate source address
  - Have our IDS/IPS/Firewall act as the destination host would - In the sense that reconstructing the packets gives     a clear indication of malicious activity.

  -Watch for connections started by one host, and taken over by another - The attacker after all has to reveal their    true source address in order to see that a port is open. This is strange behavior and we can define our rules to     prevent it.

Finding Random Source Attacks :

    - watch for many hosts will ping one host which does not exist, and the pinged host will ping back all others
      and get no reply.
    - Single Port Utilization from random hosts
    - Incremental Base Port with a lack of randomization (ex : list of 1 to 50) check Info and the first number(base port -> connection port)
    - Identical Length Fields (check Length)

SMURF attacks :
  - The attacker will send n ICMP request to live hosts with a spoofed address of the victim host
  - The live host will respond to the legitimate host with an ICMP reply
  - This mau cause ressource exhaustion on the victim host (spamming is not good for your connection)
  - check ICMP protocol, if you notice many different hosts pinging our single host, and in this case it               represents the basic nature of SMURF attacks.

Finding LAND Attacks :
  - LAND attacks use an attacker for spoofing the source IP and be the same as the destination. It's a DOS attacks
    which work throught sheer volume of traffic and port re-use.

============================

IP time to live Attacks : 
    - In a "TTL Expiry Attack," an attacker crafts IP packets with intentionally low TTL values. These packets traverse the network, with TTL values decrementing at each hop. When TTL reaches zero, routers discard the packet and send an ICMP Time Exceeded message back to the source. Attackers collect these messages to map a network's topology, but this can trigger security alerts.
  - Finding Irregularities in IP TTL (time to live)
      - most of the time attackers will use this for port scanning.
      - if there is a syn-ack return message (mean the synchronisation is done), the attacker might have                   successfully evaded one of our firewall controls.
      - Check the suspects packets to find TTL, go to Internet Protocol and search "Time to live" a low time to live mean there is a risk of an attack. You can prevent these forms of IP packet crafting attacks by implement a constrol wich discard packets with low TTL (with FireWall rules that limit incoming ICMP traffic from external source)

=======================

TCP Handshake Abnormalites :
  - Excessive SYN Flags = to nmap scanning
======================

TCP Connection Hijacking
  For more advanced actors, they might employ TCP connection hijacking. In this case the attacker will actively monitor the target connection they want to hijack.
  The attacker will then conduct sequence number prediction in order to inject their malicious packets in the correct order. During this injection they will spoof the source address to be the same as our affected machine.
  The attacker will need to block ACKs from reaching the affected machine in order to continue the hijacking. They do this either through delaying or blocking the ACK packets. As such, this attack is very commonly employed with ARP poisoning, and we might notice the following in our traffic analysis.
Right click on the infected ACK packets and select "Follow TCP stream"
===================
    



