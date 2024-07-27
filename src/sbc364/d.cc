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
  int n, q;
  cin >> n >> q;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  sort(begin(av), end(av));
  rep(_, q) {
	dbg(q);
    ll b, k;
    cin >> b >> k;
    ll ub = 100000000000000000ll;
    ll lb = -1ll;
    while (ub - lb > 1ll) {
      ll mid = (ub + lb) / 2ll;
      auto i = lower_bound(begin(av), end(av), b - mid);
      auto j = upper_bound(begin(av), end(av), b + mid);
      ll cnt = j - i;
	  // dbg(i-begin(av));	  
	  // dbg(j-begin(av));
	  // dbg(mid, b-mid, b+mid, cnt);
      if (k <= cnt)
        ub = mid;
      else // cnt < k
        lb = mid;
    }
    cout << ub << endl;
  }

  return 0;
}
