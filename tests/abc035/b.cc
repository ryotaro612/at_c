#include "abc035/b.cc"
#include <gtest/gtest.h>

TEST(abc035b, 1) {
    EXPECT_EQ(3, solve("UL?", 1));
}

TEST(abc035b, 2) {
    EXPECT_EQ(1, solve("UD?", 1));
}

TEST(abc035b, 3) {
    EXPECT_EQ(7, solve("UUUU?DDR?LLLL", 1));
}

TEST(abc035b, 4) {
    EXPECT_EQ(3, solve("UULL?", 2));
}
