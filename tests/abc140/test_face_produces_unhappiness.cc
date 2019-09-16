#include "gtest/gtest.h"
#include "abc140/face_produces_unhappiness.h"


TEST(TestFaceProducesUnhappiness, First) {
  char faces[] = {'L', 'R', 'L', 'R', 'R', 'L'};
  EXPECT_EQ(3, solve_face_produces_unhappiness(6, 1,faces));
}

TEST(TestFaceProducesUnhappiness, Second) {
  char faces[] = {'L', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'L', 'R'};
  EXPECT_EQ(9, solve_face_produces_unhappiness(13, 3, faces));
}

TEST(TestFaceProducesUnhappiness, Third) {
  char faces[] = {'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R'};
  EXPECT_EQ(9, solve_face_produces_unhappiness(10, 1, faces));
}

TEST(TestFaceProducesUnhappiness, Fourth) {
  char faces[] = {'R', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'L'};
  EXPECT_EQ(7, solve_face_produces_unhappiness(9, 2, faces));
}
