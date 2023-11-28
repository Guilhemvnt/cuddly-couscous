// test_main.cpp
#include <iostream>
#include <criterion/criterion.h>

// Prototype of the function you want to test
int add(int a, int b);

Test(add, should_add_two_numbers) {
    cr_assert_eq(add(2, 3), 5, "2 + 3 should be 5");
    cr_assert_eq(add(-2, 3), 1, "-2 + 3 should be 1");
}