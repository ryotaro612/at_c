#include "gtest/gtest.h"
#include "abc153/caracal_vs_monster.h"
using namespace std;


TEST(TestCaracalVsMonster, First) {
  EXPECT_EQ(3, caracal_vs_monster(2));
}

TEST(TestCaracalVsMonster, Second) {
  EXPECT_EQ(7, caracal_vs_monster(4));
}

TEST(TestCaracalVsMonster, Third) {
  EXPECT_EQ(1099511627775, caracal_vs_monster(1000000000000));
}

TEST(TestCaracalVsMonster, Fourth) {
  EXPECT_EQ(1, caracal_vs_monster(1));
}

TEST(TestCaracalVsMonster, Fifth) {
  EXPECT_EQ(3, caracal_vs_monster(2));
}
