#include "arc031/b.cc"
#include "gtest/gtest.h"

TEST(arc031b, 1) {
    vector<string> area = {
        "xxxxxxxxxx", "xoooooooxx", "xxoooooxxx", "xxxoooxxxx", "xxxxoxxxxx",
        "xxxxxxxxxx", "xxxxoxxxxx", "xxxoooxxxx", "xxoooooxxx", "xxxxxxxxxx"};
    EXPECT_EQ("YES", solve(area));
}
