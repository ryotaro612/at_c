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
  int n, m;
  cin >> n >> m;

  vector<int> xv(m);
  rep(i, m) {
    cin >> xv[i];
    xv[i]--;
  }
  vector<ll> prefix(n, 0);
  rep(i, m - 1) {
    int a = min(xv[i], xv[i + 1]), b = max(xv[i], xv[i + 1]);
    if (b - a < a + n - b) {
      int cost = (a+n-b) - (b-a);
      prefix[b] += cost;
      if (a) {
        prefix[0] += cost;
        prefix[a] -= cost;
      }
    } else if (b - a > a + n - b) {
      int cost = (b-a) - (a+n-b);
      prefix[a] += cost;
      prefix[b] -= cost;
    }
  }
  ll target_v = 0;
  rep(i, n) {
    if (i)
      prefix[i] += prefix[i - 1];
    target_v = max(target_v, prefix[i]);
  }
  int cut_i = 0;
  rep(i, n) {
    if (prefix[i] == target_v)
      cut_i = i;
  }
  ll res = 0;
  rep(i, m - 1) {
    int a = min(xv[i], xv[i + 1]), b = max(xv[i], xv[i + 1]);
    if (a <= cut_i && cut_i < b)
      res += (ll)(n - (b - a));
    else
      res += (ll)(b - a);
  }
  cout << res << endl;
  return 0;
}
