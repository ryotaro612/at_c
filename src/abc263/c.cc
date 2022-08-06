#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

void find_inc(int n, int m, vector<int> &cur, vector<vector<int>> &res) {
  if ((int)cur.size() == n) {
    res.push_back(vector<int>(cur));
    return;
  }
  int begin;
  if (cur.size() == 0) {
    begin = 1;
  } else {
    begin = cur.back() + 1;
  }
  for (int i = begin; i <= m; i++) {
    cur.push_back(i);
    find_inc(n, m, cur, res);
    cur.pop_back();
  }
}
#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> cur;
  vector<vector<int>> res;
  find_inc(n, m, cur, res);
  for (auto v : res) {
    for (int i = 0; i < (int)v.size(); i++) {
      cout << v[i];
      if (i == (int)v.size() - 1)
        cout << endl;
      else
        cout << " ";
    }
  }
  return 0;
}
#endif
