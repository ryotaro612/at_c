#include "gtest/gtest.h"
#include "abc164/multiple_of_2019.h"

using namespace std;

TEST(MultipleOf2019, 1) {
  EXPECT_EQ(3, multiple_of_2019("1817181712114"));
}

TEST(MultipleOf2019, 2) {
  EXPECT_EQ(2, multiple_of_2019("14282668646"));
}

TEST(MultipleOf2019, 3) {
  EXPECT_EQ(0, multiple_of_2019("2119"));
}
