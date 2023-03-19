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
  int n, m;
  cin >> n >> m;
  vector<ll> av(n), bv(m), cv;
  rep(i, n) {
    cin >> av[i];
    cv.push_back(av[i]);
  }
  rep(i, m) {
    cin >> bv[i];
    cv.push_back(bv[i]);
  }
  sort(cv.begin(), cv.end());
  map<ll, int> mp;
  rep(i, cv.size()) { mp[cv[i]] = i + 1; }
  rep(i, n) { cout << mp[av[i]] << " \n"[i == n - 1]; }
  rep(i, m) { cout << mp[bv[i]] << " \n"[i == m - 1]; }

  return 0;
}
#endif
