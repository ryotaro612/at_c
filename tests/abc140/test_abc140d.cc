#include "gtest/gtest.h"
#include "abc140/abc140d.h"


TEST(abc140d, 1) {
  char faces[] = {'L', 'R', 'L', 'R', 'R', 'L'};
  EXPECT_EQ(3, abc140d(6, 1,faces));
}

TEST(abc140d, 2) {
  char faces[] = {'L', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'L', 'R'};
  EXPECT_EQ(9, abc140d(13, 3, faces));
}

TEST(abc140d, 3) {
  char faces[] = {'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R'};
  EXPECT_EQ(9, abc140d(10, 1, faces));
}

TEST(abc140d, 4) {
  char faces[] = {'R', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'L'};
  EXPECT_EQ(7, abc140d(9, 2, faces));
}
