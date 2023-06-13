#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
void debug_() { cout << endl; }
template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  cout << "[";
  string s[2] = {", ", "]"};
  rep(i, v.size()) { cout << v[i] << s[i == int(v.size()) - 1]; }
  return os;
}

#ifdef ONLINE_JUDGE
int main() {
  int k;
  cin >> k;
  vector<ll> av(k);
  rep(i, k) cin >> av[i];
  ll ub = 2ll, lb = 2ll;
  for (int i = k - 1; i >= 0; i--) {
    if (ub < av[i]) {
      cout << "-1\n";
      return 0;
    }
    if (lb / av[i] == ub / av[i] && lb / av[i] * av[i] < lb) {
      cout << "-1\n";
      return 0;
    }

    ll next_lb = lb / av[i] * av[i];
    if (lb / av[i] * av[i] < lb) {
      next_lb += av[i];
    }
    ll next_ub = ub / av[i] * av[i] + (av[i] - 1ll);
    debug("next", next_lb, next_ub);
    if (!(lb <= next_lb && (ub / av[i] * av[i]) <= ub)) {
      cout << "-1\n";
      return 0;
    }
    ub = next_ub;
    lb = next_lb;
    debug(i, lb, ub);
  }
  cout << lb << " " << ub << "\n";

  return 0;
}
#endif
