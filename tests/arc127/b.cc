#include "arc127/b.cc"
#include <gtest/gtest.h>

// TEST(arc127b, 1) {
//     vector<string> res = solve(2, 2);
//     vector<string> ans = {"00", "02", "11", "12", "20", "21"};
//     EXPECT_EQ(ans, res);
// }

	// N = 1, L = 1
	// (0), (1), (2)
	// ->(2)
	// N = 1, L = 2
	// (0, 0), (1, 1), (2, 2)
	// (0, 2), (1, 1), (2, 0)
	// -> (2, 0)
	// N = 1 L = 3
	// (0, 0, 0), (1, 1, 1), (2, 2, 2)
	// (2, 0, 0), (1, 1, 1), (0, 2, 2)
	// N = 1 L = 4 
	// (0, 0, 0, 0), (1, 1, 1, 1), (2, 2, 2, 2)
	// (2, 0, 0, 0), (1, 1, 1, 1), (0, 2, 2, 2)
	// N = 1なら(2, 0, ....)
	// N = 2, L = 2
    // 00 02 11 12 20 21
	// -> 21
	// N = 3, L = 2
	// 0 0 0, 0 0 0, 0 0 0, 1 1 1, 1 1 1, 1 1 1, 2 2 2, 2 2 2, 2 2 2
	// 2 0 0, 2 0 1, 2 0 2, 1 2 0, 0 2 0, 0 1 2, 1 1 1, 1 1 2, 0 2 1

	// N = 2, L = 3
    // 0 0 0, 1 1 1, 2 2 2, 0 0 0, 1 1 1, 2 2 2
	// 2 0 0, 1 1 2, 2 0 1, 0 2 0, 1 1 1, 0 2 2
	// 2000からいくらたしたか