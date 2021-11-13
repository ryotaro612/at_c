#include <abc110/c.cc>
#include <gtest/gtest.h>

TEST(abc110c, 1) { EXPECT_EQ("Yes", solve("azzel", "apple")); }

TEST(abc110c, 2) { EXPECT_EQ("No", solve("chokudai", "redcoder")); }

TEST(abc110c, 3) {
    EXPECT_EQ("Yes", solve("abcdefghijklmnopqrstuvwxyz",
                           "ibyhqfrekavclxjstdwgpzmonu"));
}
