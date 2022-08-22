#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

int sub(int start, ll total, vector<ll> &prefix) {

  int lb = start - 1, ub = prefix.size();
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (total < prefix[mid] - prefix[start]) {
      ub = mid;
    } else
      lb = mid;
  }
  return lb;
}

string solve(ll n, ll p, ll q, ll r, vector<ll> &av) {

  vector<ll> prefix(n + 1, 0);
  rep(i, n) { prefix[i + 1] = av[i] + prefix[i]; }

  for (int i = 0; i < n - 2; i++) {
    int y_start = sub(i, p, prefix);
    if (prefix[y_start] - prefix[i] != p)
      continue;
    int z_start = sub(y_start, q, prefix);
    if (prefix[z_start] - prefix[y_start] != q)
      continue;
    int w_end = sub(z_start, r, prefix);
    if (prefix[w_end] - prefix[z_start] != r)
      continue;
    return "Yes";
  }
  return "No";
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, p, q, r;
  cin >> n >> p >> q >> r;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, p, q, r, av) << endl;
  return 0;
}
#endif
