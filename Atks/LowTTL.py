import socket

# Define the destination IP address and port
dest_ip = "192.168.1.192"
dest_port = 80

# Create a raw socket with IPPROTO_RAW (IP protocol)
s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_RAW)

# Set the TTL value (e.g., TTL=5)
ttl_value = 5
s.setsockopt(socket.IPPROTO_IP, socket.IP_TTL, ttl_value)

# Craft the packet with a custom TTL
packet = (
    b'\x45\x00\x00\x28'  # IP Header: Version, IHL, Type of Service, Total Length
    b'\x00\x01\x00\x00'  # IP Header: Identification, Flags, Fragment Offset
    b'\x40\x06\x00\x00'  # IP Header: TTL (set by setsockopt), Protocol, Header Checksum
    b'\x0a\x0a\x0a\x02'  # IP Header: Source Address
    b'\x0a\x0a\x0a\x02'  # IP Header: Destination Address
    b'\x00\x50\x39\x39'  # TCP Header: Source Port (80), Destination Port
    b'\x00\x00\x00\x00'  # TCP Header: Sequence Number
    b'\x00\x00\x00\x00'  # TCP Header: Acknowledgement Number
    b'\x50\x02\x71\x10'  # TCP Header: Data Offset, Reserved, Flags, Window Size
    b'\xe6\x32\x00\x00'  # TCP Header: Checksum, Urgent Pointer
)

# Send the packet to the destination IP and port
s.sendto(packet, (dest_ip, dest_port))
