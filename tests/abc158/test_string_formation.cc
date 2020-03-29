#include<vector>
#include "gtest/gtest.h"
#include "abc158/string_formation.h"

using namespace std;

TEST(StringFormation, 1) {
  Query queries[] = {
    Query(true, "p"), 
    Query(), 
    Query(false, "c"), 
    Query()
  };
  EXPECT_EQ(
      "cpa", 
      string_formation("a", 4, queries));
}

TEST(StringFormation, 2) {
  Query queries[] = {
    Query(false, "a"), 
    Query(true, "b"), 
    Query(), 
    Query(false, "c"), 
    Query(),
    Query(),
  };
  EXPECT_EQ(
      "aabc", 
      string_formation("a", 6, queries));
}

TEST(StringFormation, 3) {
  Query queries[] = {
    Query(true, "x"), 
  };
  EXPECT_EQ(
      "xy", 
      string_formation("y", 1, queries));
}
