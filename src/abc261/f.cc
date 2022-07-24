#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll sum(int i, vector<ll> &bit) {
  ll s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, int x, vector<ll> &bit) {
  while (i <= (int)bit.size() - 1) {
    bit[i] += x;
    i += i & -i;
  }
}

ll count_inversion_num(vector<int> &xv, vector<ll> &bit) {
  ll res = 0ll;
  for (int i = 0; i < (int)xv.size(); i++) {
    res += i - sum(xv[i], bit);
    add(xv[i], 1, bit);
  }
  for (int i = 0; i < (int)xv.size(); i++) {
    add(xv[i], -1, bit);
  }
  return res;
}

ll solve(int n, vector<int> &cv, vector<int> &xv) {
  vector<ll> bit(300001, 0);
  ll res = count_inversion_num(xv, bit);
  map<int, vector<int>> mp;
  rep(i, n) { mp[cv[i]].push_back(xv[i]); }
  for (auto [color, v] : mp) {
    // cout << " ==" << endl;
    // for (auto c : v)
    //   cout << c << endl;
    ll count = count_inversion_num(v, bit);
    // cout << "color: " << color << " " << count << endl;
    res -= count;
  }

  return res;
}

//#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> cv(n), xv(n);
  rep(i, n) cin >> cv[i];
  rep(i, n) cin >> xv[i];
  cout << solve(n, cv, xv) << endl;

  return 0;
}
//#endif
