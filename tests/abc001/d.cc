#include "abc001/d.cc"
#include <gtest/gtest.h>

TEST(abc001d, 1) {
    vector<pair<int, int>> ans = {make_pair(1105, 1210), make_pair(1320, 1405)};
    EXPECT_EQ(ans,
              solve(4, {"1148-1210", "1323-1401", "1106-1123", "1129-1203"}));
}

TEST(abc001d, 2) {
    vector<pair<int, int>> ans = {make_pair(0, 2400)};
    EXPECT_EQ(ans, solve(1, {"0000-2400"}));
}

TEST(abc001d, 3) {
    vector<pair<int, int>> ans = {make_pair(1155, 1310), make_pair(1315, 1320)};
    EXPECT_EQ(ans, solve(6, {"1157-1306", "1159-1307", "1158-1259", "1230-1240",
                             "1157-1306", "1315-1317"}));
}
