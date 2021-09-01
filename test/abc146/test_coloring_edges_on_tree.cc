#include "gtest/gtest.h"
#include <vector>
#include "abc146/coloring_edges_on_tree.h"

using namespace std;

TEST(TestColoringEdgesOnTree, First) {  
  vector<int> ans = {2, 1, 2};
  vector<int> a = {1, 2};
  vector<int> b = {2, 3};
  EXPECT_EQ(ans, coloring_edges_on_tree(3, a, b));
}

TEST(TestColoringEdgesOnTree, Second) {
  vector<int> ans = {4, 1, 2, 3, 4, 1, 1, 2};
  vector<int> a = {1, 2, 2, 2, 4, 5, 6};
  vector<int> b = {2, 3, 4, 5, 7, 6, 8};
  EXPECT_EQ(ans, coloring_edges_on_tree(8, a, b));
}

TEST(TestColoringEdgesOnTree, Third) {
  vector<int> ans = {5, 1, 2, 3, 4, 5};
  vector<int> a = {1, 1, 1, 1, 1};
  vector<int> b = {2, 3, 4, 5, 6};
  EXPECT_EQ(ans, coloring_edges_on_tree(6, a, b));
}

