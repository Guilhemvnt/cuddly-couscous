# cuddly-couscous IDS network

## Finding Deauthentication Attacks

## Finding Decoy Scanning Attempts

When analyzing network traffic, be vigilant for the following signs of decoy scanning attempts:

- Look for multiple instances of fragmented IP protocol in the Info field, as this could indicate an attack.
- Check TCP traffic from legitimate source addresses.
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

## Strange HTTP Headers
   Discorver Strange HTTP Headers -> check Wierd Host, Unsual HTTP Verbs, Changed User Agents
    - display HTTP headers with : http

   Finding Strange Host Heardes : 
      - First we exclude entries that use real headers : http.request and (!(http.host == "ip or domain name"))
   Check HyperText Transfer Protocol :
      - If we spot 127.0.0.1 as Host (request from localhost), or admin. This should be flag cause it's can be an attemp for          gain levels of access. It's can prove the use of proxy tools like Burp.
         For counter this we might check if our web server is up to date.

   Analysing Code 400s and Request Smuggling :
         - check responce code in 400s range : http.responce.code == 400, check precisely one = http.responce.code === 400)

**Disclaimer:** This repository is for educational purposes only. Use this information responsibly and within legal boundaries.
