#include "gtest/gtest.h"
#include <vector>
#include "abc169/div_game.h"
using namespace std;


TEST(DivGame, 1) {
  long long a = div_game(24);
  EXPECT_EQ(3, a);
}

TEST(DivGame, 2) {
  long long a = div_game(1);
  EXPECT_EQ(0, a);
}

TEST(DivGame, 3) {
  long long a = div_game(64);
  EXPECT_EQ(3, a);
}

TEST(DivGame, 4) {
  long long a = div_game(1000000007);
  EXPECT_EQ(1, a);
}

TEST(DivGame, 5) {
  long long a = div_game(997764507000);
  EXPECT_EQ(7, a);
}
