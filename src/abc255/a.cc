#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int r, c;
  cin >> r >> c;
  vector<vector<int>> av(2, vector<int>(2));
  cin >> av[0][0] >> av[0][1] >> av[1][0] >> av[1][1];
  cout << av[r - 1][c - 1] << endl;
  return 0;
}
#endif
