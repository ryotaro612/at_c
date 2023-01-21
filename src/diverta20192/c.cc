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

void solve_all_neg(vector<ll> &av) {
  int n = av.size();
  ll res = av[n - 1];
  vector<pair<ll, ll>> pairs;
  rep(i, n - 1) {
    pairs.push_back({res, av[i]});
    res -= av[i];
  }
  cout << res << endl;
  rep(i, pairs.size()) {
    cout << pairs[i].first << " " << pairs[i].second << endl;
  }
}

void solve_all_noneg(vector<ll> &av) {
  int n = av.size();

  vector<pair<ll, ll>> pairs;
  ll res = av[0];
  for (int i = 1; i < n - 1; i++) {
    pairs.push_back({res, av[i]});
    res -= av[i];
  }
  pairs.push_back({av[n - 1], res});
  res = av[n - 1] - res;
  cout << res << endl;
  rep(i, pairs.size()) {
    cout << pairs[i].first << " " << pairs[i].second << endl;
  }
  cout << endl;
}
void solve_all(vector<ll> &av) {
  vector<ll> nonegv;
  vector<ll> negv;
  for (auto e : av) {
    if (e >= 0)
      nonegv.push_back(e);
    else
      negv.push_back(e);
  }

  ll res = nonegv[0];
  vector<pair<ll, ll>> pairs;
  for (int i = 1; i < as_int(negv.size()); i++) {
    pairs.push_back({res, negv[i]});
    res -= negv[i];
  }
  ll res2 = negv[0];
  for (int i = 1; i < as_int(nonegv.size()); i++) {
    pairs.push_back({res2, nonegv[i]});
    res2 -= nonegv[i];
  }
  pairs.push_back({res, res2});
  cout << res - res2 << endl;
  for (auto [a, b] : pairs) {
    cout << a << " " << b << endl;
  }
}
//#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  sort(av.begin(), av.end());
  if (av[n - 1] < 0)
    solve_all_neg(av);
  else if (0 <= av[0])
    solve_all_noneg(av);
  else
    solve_all(av);
  return 0;
}
//#endif
