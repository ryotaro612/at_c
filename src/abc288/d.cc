#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__       \
       << " = ";                                                               \
  debug_(__VA_ARGS__);
#else
#define dbg(...)
#endif
template <typename Os, typename... Ts>
Os &operator<<(Os &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Os, typename T>
typename enable_if<is_same<Os, ostream>::value, Os &>::type
operator<<(Os &os, const T &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}

void debug_() { cerr << "\e[39m" << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cerr << H << " ";
  debug_(T...);
}
int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> av(n);
  rep(i, n) { cin >> av[i]; }
  vector<vector<ll>> prefix_sum(k, vector<ll>(n + 1, 0));
  rep(i, n) {
    rep(j, k) {
      prefix_sum[j][i + 1] = prefix_sum[j][i];
      if (i % k == j)
        prefix_sum[j][i + 1] += av[i];
    }
  }

  int q;
  cin >> q;
  dbg("doge");
  rep(_, q) {
    int l, r;
    cin >> l >> r, --l;
    bool ok = true;
    rep(i, k) {
      ok = ok && ((prefix_sum[0][r] - prefix_sum[0][l]) ==
                  (prefix_sum[i][r] - prefix_sum[i][l]));
    }

    if (ok)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
