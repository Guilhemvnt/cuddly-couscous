# cuddly-couscous

## Discover Wireshark Software for Network Traffic Analysis

To get started with network traffic analysis using Wireshark, follow these steps:

1. Download the necessary pcap files:

   ```bash
   wget -O file.zip 'https://academy.hackthebox.com/storage/resources/pcap_files.zip' && mkdir tempdir && unzip file.zip -d tempdir && mkdir -p pcaps && mv tempdir/Intermediate_Network_Traffic_Analysis/* pcaps/ && rm -r tempdir file.zip
   ```

2. After obtaining the pcap files, proceed with the analysis.

## Filtering Deauthentication Frames in Wireshark

To filter deauthentication frames in Wireshark, you can use the following display filter:

```bash
(wlan.bssid == F8:14:FE:4D:E6:F1) and (wlan.fc.type == 0) && (wlan.fc.type_subtype == 12)
```

- `(wlan.bssid == F8:14:FE:4D:E6:F1)` identifies the attacker's WLAN device.
- `(wlan.fc.type == 0) && (wlan.fc.type_subtype == 12)` filters frames with type 0 and subtype 12, commonly used by attack tools.

## Finding Decoy Scanning Attempts

When analyzing network traffic, be vigilant for the following signs of decoy scanning attempts:

- Look for multiple instances of fragmented IP protocol in the Info field, as this could indicate an attack.
- Check TCP traffic from legitimate source addresses.
- Consider configuring your IDS/IPS/Firewall to act as the destination host to detect malicious activity.
- Watch for connections initiated by one host and taken over by another, as attackers may reveal their true source address.

## Identifying Random Source Attacks

Detecting random source attacks requires attention to several factors:

- Monitor for multiple hosts pinging a non-existent host that responds to all pings.
- Keep an eye on single-port utilization from random hosts.
- Look for incremental base port numbers without randomization, especially in the Info field.
- Examine packets for identical length fields.

## Detecting SMURF Attacks

SMURF attacks involve sending ICMP requests to live hosts with a spoofed victim host address. To detect SMURF attacks:

- Examine ICMP protocol traffic.
- If you observe many different hosts pinging a single host, it may indicate a SMURF attack.

## Finding LAND Attacks

LAND attacks involve an attacker spoofing their source IP to match the destination. These attacks rely on sheer traffic volume and port re-use. Be cautious of this type of DOS attack.

## IP Time to Live Attacks

In IP time to live attacks, attackers craft packets with intentionally low TTL values to map a network's topology. Look for irregularities in IP TTL values, especially during port scanning attempts. A low TTL could indicate a risk of an attack. Implement firewall rules to discard packets with low TTL to mitigate such attacks.

## TCP Handshake Abnormalities

Excessive SYN flags may indicate nmap scanning or other suspicious activity during the TCP handshake.

## TCP Connection Hijacking

Advanced attackers may attempt TCP connection hijacking. This involves monitoring a target connection, conducting sequence number prediction, and spoofing source addresses. Attackers may block ACK packets to continue hijacking. Be vigilant for signs of ARP poisoning in your traffic analysis.

For more detailed instructions and analysis techniques, refer to the respective sections in this repository.

**Disclaimer:** This repository is for educational purposes only. Use this information responsibly and within legal boundaries.
