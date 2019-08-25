#include<string>
#include "gtest/gtest.h"
#include "abc132/divide_the_problem.h"

TEST(TestDivideTheProblem, First) {
    std::string arg = "9 1 4 4 6 7";
    EXPECT_EQ(2, solve_divide_the_problem(6, arg));
}
TEST(TestDivideTheProblem, Second) {
    std::string arg = "9 1 14 5 5 4 4 14";
    EXPECT_EQ(0, solve_divide_the_problem(8, arg));
}

TEST(TestDivideTheProblem, Third) {
    std::string arg = "99592 10342 29105 78532 83018 11639 92015 77204 30914 21912 34519 80835 100000 1";
    EXPECT_EQ(42685, solve_divide_the_problem(14, arg));
}