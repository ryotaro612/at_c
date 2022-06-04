#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

string solve(int n, int k, vector<ll> &av) {
  vector<multiset<ll>> sorter(k);
  rep(i, k) {
    for (int j = i; j < n; j += k) {
      sorter[i].insert(av[j]);
    }
  }
  ll counter = *sorter[0].begin();

  int i = 0;
  // for (auto e : sorter[0]) {
  //   cout << e << " ";
  // }
  // cout << endl;
  // for (auto e : sorter[1]) {
  //   cout << e << " ";
  // }
  // cout << endl;
  // for (auto e : sorter[2]) {
  //   cout << e << " ";
  // }
  // cout << endl;
  while (true) {
    bool exist = false;
    if (!sorter[i].empty()) {
      if (*sorter[i].begin() < counter)
        return "No";
      else
        counter = *sorter[i].begin();
      sorter[i].erase(sorter[i].begin());
      exist = true;
    }
    i += 1;
    i %= k;
    if (!exist)
      break;
  }

  return "Yes";
}

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, k, av) << endl;
  return 0;
}
#endif
