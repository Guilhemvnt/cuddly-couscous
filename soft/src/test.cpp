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
    sniffer.setDevice("1234");

    cr_assert_eq(sniffer.getNetworkInterface(), "lo");

    for (auto i : sniffer.getDevices())
        cr_assert_eq(i, "1234");

    std::cout << getSubnetMask("127.0.0.1") << std::endl;
    cr_assert_eq(getSubnetMask("127.0.0.1"), "255.255.0.0");

}

Test(test, test2)
{
    cr_assert_eq(1, 1);
}




