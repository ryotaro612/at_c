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

// #ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n + 1, 0);
  rep(i, n) cin >> av[i];

  // debug(23, "a", "b", 32);

  ll prev = 0ll, res = 0ll;
  if (av[0]) {
    cout << "-1\n";
    return 0;
  }

  for (ll i = 1ll; i < n + 1ll; i++) {
    if (av[i] == 0) {
      ll min_t = 0;
      for (ll j = i - 1ll; j > prev; j--) {
        if (av[j] < min_t) {
          cout << "-1\n";
          return 0;
        }
        if (av[j] + 1ll == av[j + 1]) {
          min_t = max(min_t - 1ll, av[j] - 1ll);
        } else {
          if (j - prev < av[j]) {
            cout << "-1\n";
            return 0;
          }
          min_t = max(min_t - 1ll, av[j] - 1ll);
          res += av[j];
        }
      }
      prev = i;
    }
  }

  cout << res << endl;

  return 0;
}
// #endif
