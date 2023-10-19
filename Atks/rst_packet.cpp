#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {
    // Create a raw socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sockfd < 0) {
        perror("Socket creation error");
        return 1;
    }

    // Fill in the IP header
    struct ip ipHeader;
    memset(&ipHeader, 0, sizeof(ipHeader));
    ipHeader.ip_hl = 5;
    ipHeader.ip_v = 4;
    ipHeader.ip_len = sizeof(ipHeader) + sizeof(struct tcphdr);
    ipHeader.ip_ttl = 64;
    ipHeader.ip_p = IPPROTO_TCP;
    ipHeader.ip_src.s_addr = inet_addr(argv[1]); // Set a valid IP address here
    ipHeader.ip_dst.s_addr = inet_addr(argv[2]); // Set a valid destination IP

    // Fill in the TCP header
    struct tcphdr tcpHeader;
    memset(&tcpHeader, 0, sizeof(tcpHeader));
    tcpHeader.source = htons(12345);  // Source port
    tcpHeader.dest = htons(8080);       // Destination port
    tcpHeader.seq = 0;
    tcpHeader.ack_seq = 0;
    tcpHeader.doff = 5;  // Data offset (header length)
    tcpHeader.fin = 0;
    tcpHeader.syn = 0;
    tcpHeader.rst = 1;  // Set RST flag
    tcpHeader.psh = 0;
    tcpHeader.ack = 0;
    tcpHeader.urg = 0;
    tcpHeader.window = htons(5840);  // Maximum allowed window size
    tcpHeader.check = 0;             // Checksum will be computed by the kernel
    tcpHeader.urg_ptr = 0;

    // Construct the packet
    char packet[4096];
    memset(packet, 0, sizeof(packet));
    memcpy(packet, &ipHeader, sizeof(ipHeader));
    memcpy(packet + sizeof(ipHeader), &tcpHeader, sizeof(tcpHeader));

    // Set the destination address and port
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = ipHeader.ip_dst.s_addr;

    // Send the packet
    ssize_t bytes_sent = sendto(sockfd, packet, ipHeader.ip_len, 0,(struct sockaddr*)&dest_addr, sizeof(dest_addr));
    if (bytes_sent < 0) {
        perror("Packet sending error");
        close(sockfd);
        return 1;
    }

    close(sockfd);
    return 0;
}
