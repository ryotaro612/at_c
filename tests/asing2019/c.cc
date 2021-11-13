#include "aising2019/c.cc"
#include <gtest/gtest.h>

TEST(asing2019c, 1) {

    vector<string> s = {".#.", "..#", "#.."};
    EXPECT_EQ(10, solve(3, 3, s));
}