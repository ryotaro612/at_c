#include<vector>
#include<deque>
#include<string>
#include "gtest/gtest.h"
#include "abc158/string_formation.h"

using namespace std;

string to(deque<char> d) {
  string s = "";
  while(!d.empty()) {
    s = s + d.front();
    d.pop_front();
  }
  return s;
}

TEST(StringFormation, 1) {
  Query queries[] = {
    Query(true, "p"), 
    Query(), 
    Query(false, "c"), 
    Query()
  };
  
  EXPECT_EQ(
      "cpa", 
      to(string_formation("a", 4, queries)));
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
      to(string_formation("a", 6, queries)));
}

TEST(StringFormation, 3) {
  Query queries[] = {
    Query(true, "x"), 
  };
  EXPECT_EQ(
      "xy", 
      to(string_formation("y", 1, queries)));
}
