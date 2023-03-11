#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n, 0);
  rep(i, n) cin >> av[i];
  vector<bool> called(n, false);
  rep(i, n) {
    --av[i];
    if (!called[i]) {
      called[av[i]] = true;
    }
  }
  vector<int> res;
  rep(i, n) {
    if (called[i] == false)
      res.push_back(i + 1);
  }
  cout << res.size() << endl;
  rep(i, res.size()) { cout << res[i] << " \n"[i == as_int(res.size()) - 1]; }
  return 0;
}
#endif
