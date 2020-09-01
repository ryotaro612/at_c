#include "gtest/gtest.h"
#include "abc108/d.cc"
typedef long long ll;
using namespace std;

void check(ll u, ll v, ll w, I edge) {
  EXPECT_EQ(u, edge.u);
  EXPECT_EQ(v, edge.v);
  EXPECT_EQ(w, edge.w);
}

TEST(abc108d, 1) {
  auto ans = d(4);
  EXPECT_EQ(3, ans.n);
  EXPECT_EQ(4, ans.m);
  auto edges = ans.edges;
  check(1, 2, 1, edges[0]);
  check(1, 2, 0, edges[1]);
  check(2, 3, 2, edges[2]);
  check(2, 3, 0, edges[3]);
}

TEST(abc108d, 2) {
  auto ans = d(5);
  EXPECT_EQ(3, ans.n);
  EXPECT_EQ(5, ans.m);
  auto edges = ans.edges;
  check(1, 2, 1, edges[0]);
  check(1, 2, 0, edges[1]);
  check(2, 3, 2, edges[2]);
  check(2, 3, 0, edges[3]);
  check(1, 3, 4, edges[4]);
}

TEST(abc108d, 3) {
  auto ans = d(2);
  EXPECT_EQ(2, ans.n);
  EXPECT_EQ(2, ans.m);
  auto edges = ans.edges;
  check(1, 2, 1, edges[0]);
  check(1, 2, 0, edges[1]);
}

TEST(abc108d, 4) {
  auto ans = d(7);
  EXPECT_EQ(3, ans.n);
  EXPECT_EQ(6, ans.m);
  auto edges = ans.edges;
  check(1, 2, 1, edges[0]);
  check(1, 2, 0, edges[1]);
  check(2, 3, 2, edges[2]);
  check(2, 3, 0, edges[3]);
  check(2, 3, 5, edges[4]);
  check(1, 3, 4, edges[5]);
}

TEST(abc108d, 5) {
  auto ans = d(8);
  EXPECT_EQ(4, ans.n);
  EXPECT_EQ(6, ans.m);
  auto edges = ans.edges;
  check(1, 2, 1, edges[0]);
  check(1, 2, 0, edges[1]);
  check(2, 3, 2, edges[2]);
  check(2, 3, 0, edges[3]);
  check(3, 4, 4, edges[4]);
  check(3, 4, 0, edges[5]);
}
