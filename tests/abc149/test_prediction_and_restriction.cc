#include "gtest/gtest.h"
#include "abc149/prediction_and_restriction.h"

using namespace std;

TEST(TestPredictionAndRestriction, First) {
  char t[]  = {'r', 's', 'r', 'p', 'r'};
  EXPECT_EQ(
      27, 
      prediction_and_restriction(5, 2, 8, 7, 6, t));
}

TEST(TestPredictionAndRestriction, Second) {
  char t[]  = {'s', 's', 's', 's', 'p', 'p', 'r'};
  EXPECT_EQ(
      211, 
      prediction_and_restriction(7, 1, 100, 10, 1, t));
}

TEST(TestPredictionAndRestriction, Third) {
  char t[] = {
   'r', 's', 'p', 's', 's' , 'p', 's' ,'p', 's', 'r', 'p', 's', 'p', 's', 'p', 'p', 'p', 'r', 'p', 's', 'p', 'r', 'p', 's', 's', 'p', 'r', 'p', 's', 'r'};

  EXPECT_EQ(
      4996, 
      prediction_and_restriction(30, 5, 325, 234, 123, t));
}
