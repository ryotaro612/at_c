#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int count(int n, vector<int> &av, int target) {
  int res = 0;
  int count = 0;
  rep(i, n) {
    if (av[i] == target) {
      count++;
      res = max(res, count);
    } else
      count--;
    if (count < 0)
      count = 0;
  }
  return res;
}

int solve(int n, vector<int> &av) {
  int res = 1;
  res += count(n, av, 1);
  res += count(n, av, 0);
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, av) << endl;
  return 0;
}
#endif
