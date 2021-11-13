#include "gtest/gtest.h"
#include <vector>
#include "abc170/not_divisible.h"
#include <fstream>
using namespace std;


TEST(NotDivisible, 1) {
  long long n = 5;
  vector<long long> a = {24, 11, 8, 3, 16};
  EXPECT_EQ(3, not_divisible(n, a));
}

TEST(NotDivisible, 2) {
  long long n = 4;
  vector<long long> a = {5, 5, 5, 5};
  EXPECT_EQ(0, not_divisible(n, a));
}

TEST(NotDivisible, 3) {
  long long n = 10;
  vector<long long> a = {33, 18, 45, 28, 8, 19, 89, 86, 2, 4};
  EXPECT_EQ(5, not_divisible(n, a));
}

TEST(NotDivisible, 4) {
  long long n = 1;
  vector<long long> a = {33};
  EXPECT_EQ(1, not_divisible(n, a));
}

TEST(NotDivisible, 5) {
  long long n = 2;
  vector<long long> a = {33, 33};
  EXPECT_EQ(0, not_divisible(n, a));
}

TEST(NotDivisible, 6) {
  long long n = 3;
  vector<long long> a = {2, 33, 33};
  EXPECT_EQ(1, not_divisible(n, a));
}
TEST(NotDivisible, 7) {
  long long n = 93;
  vector<long long> a = {951, 299, 994, 913, 105, 760, 468, 12, 613, 158, 61, 536, 877, 688, 548, 81, 398, 916, 378, 556, 871, 268, 814, 220, 18, 455, 913, 677, 239, 697, 590, 520, 261, 885, 734, 749, 473, 384, 641, 76, 612, 28, 86, 144, 205, 772, 201, 999, 88, 940, 699, 873, 938, 44, 285, 272, 342, 219, 648, 254, 314, 421, 988, 617, 755, 921, 820, 257, 565, 376, 454, 965, 513, 253, 350, 834, 47, 275, 866, 450, 102, 159, 790, 814, 364, 406, 851, 236, 298, 288, 999,  238,  283};
  EXPECT_EQ(67, not_divisible(n, a));
}


