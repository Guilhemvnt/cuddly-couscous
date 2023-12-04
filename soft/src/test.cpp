/*
** EPITECH PROJECT, 2023
** cuddly-couscous
** File description:
** Test
*/

#include "test.hpp"

Test(test, test)
{
    Sniffer sniffer;

    sniffer.setNetworkInterface("lo");
    cr_assert_eq(sniffer.getNetworkInterface(), "lo");
}

Test(test, test2)
{
    Sniffer sniffer;
    sniffer.setDevice("1234");
    for (auto i : sniffer.getDevices())
        cr_assert_eq(i, "1234");
}

Test(test, test3)
{
    Sniffer sniffer;
    sniffer.setLogsName("test.txt");
    cr_assert_eq(sniffer.getLogsName(), "test.txt");
}

Test(test, test4)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("lo", BUFSIZ, 1, 1000, errbuf);
    cr_assert_not_null(handle);
    pcap_close(handle);
}
