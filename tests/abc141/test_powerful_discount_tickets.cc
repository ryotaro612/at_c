#include "gtest/gtest.h"
#include "abc141/powerful_discount_tickets.h"

TEST(TestPowerfulDiscountTickets, First) {
  int a [] = {2, 13, 8};
  EXPECT_EQ(9, powerful_discount_tickets(3, 3, a));
}

TEST(TestPowerfulDiscountTickets, Second) {
  int a [] = {1, 9, 3, 5};
  EXPECT_EQ(6, powerful_discount_tickets(4, 4, a));
}

TEST(TestPowerfulDiscountTickets, Third) {
  int a [] = {1000000000};
  EXPECT_EQ(0, powerful_discount_tickets(1, 100000, a));
}

TEST(TestPowerfulDiscountTickets, Fourth) {
  int a [] = {1000000000,
	      1000000000,
	      1000000000,
	      1000000000,
	      1000000000,
	      1000000000,
	      1000000000,
	      1000000000,
	      1000000000,
	      1000000000};
  EXPECT_EQ(9500000000, powerful_discount_tickets(10, 1, a));
}
