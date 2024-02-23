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
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  map<ll, vector<ll>> mp;
  rep(i, n) {
    if (av[i] < i + 1) {
      cout << 0 << endl;
      return 0;
    }
    if (i + 1 < av[i]) {
      mp[av[i]].push_back(i + 1);
    }
  }
  vector<int> assign;
  for (auto &[k, vec] : mp) {
    sort(begin(vec), end(vec));
    dbg(k, av[k-1]);
    if(av[k-1] != k) {
      cout << 0 <<endl;
      return 0;
    }
    assign.push_back(k);
    for (int i = vec.size() - 1; i > 0; i--) {
      assign.push_back(vec[i]);
    }
  }
  sort(begin(assign), end(assign));
  dbg(assign);
  ll mod = 998244353ll;
  ll res = 1;
  ll offset = 0;
  rep(i, n) {
    if (av[i] == i + 1) {

      ll cnt = upper_bound(begin(assign), end(assign), av[i]) - begin(assign);
      dbg(av[i], cnt);
      res *= (ll)(av[i] - cnt - offset);
      if (res < 0) {
        cout << 0 << endl;
        return 0;
      }
      offset++;
      res %= mod;
    }
  }
  cout << res << endl;
  return 0;
}
