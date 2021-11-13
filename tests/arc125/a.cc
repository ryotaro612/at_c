#include "arc125/a.cc"
#include <gtest/gtest.h>
TEST(arc125a, 1) {
	vector<int> s= {0, 0, 1};
	vector<int> t= {0, 1, 1, 0};
	EXPECT_EQ(6, solve(s.size(), t.size(), s, t));
}

TEST(arc125a, 2) {
	vector<int> s= {0};
	vector<int> t= {1};
	EXPECT_EQ(-1, solve(s.size(), t.size(), s, t));
}

TEST(arc125a, 3) {
	vector<int> s= {0};
	vector<int> t= {0, 0};
	EXPECT_EQ(2, solve(s.size(), t.size(), s, t));
}

TEST(arc125a, 4) {
	vector<int> s= {1, 1, 0, 0, 1, 1};
	vector<int> t= {0, 0};
	EXPECT_EQ(4, solve(s.size(), t.size(), s, t));
}