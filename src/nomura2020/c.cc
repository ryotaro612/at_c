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

ll mypow(ll x, ll n) {
  ll res = 1ll;
  while (n) {
    if (n & 1)
      res *= x;
    n >>= 1;
    x *= x;
  }
  return res;
}

bool sub(vector<ll> &av, vector<ll> &branch, int depth) {
  if (depth == as_int(av.size()))
    return branch[depth - 1] == 0;
  if (depth == 0) {
    if (av[0] == 0) {
      branch[0] = min(branch[0], 1ll);
      return sub(av, branch, depth + 1);
    } else {
      return false;
    }
  }
  branch[depth] = min(branch[depth], branch[depth - 1] * 2ll - av[depth]);
  if (branch[depth] < 0)
    return false;
  return sub(av, branch, depth + 1);
}

//#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n + 1);
  rep(i, n + 1) cin >> av[i];

  vector<ll> branch(n + 1, 0);
  branch[n] = 0ll;
  for (int i = n - 1; i >= 0; i--)
    branch[i] = av[i + 1] + branch[i + 1];

  if (n == 0) {
    if (av[0] == 1)
      cout << 1 << endl;
    else
      cout << -1 << endl;
    return 0;
  }
  if (!sub(av, branch, 0)) {
    cout << -1 << endl;
    return 0;
  }

  ll res = 0ll;
  rep(i, n + 1) { res += av[i] + branch[i]; }
  cout << res << endl;
  return 0;
}
//#endif
