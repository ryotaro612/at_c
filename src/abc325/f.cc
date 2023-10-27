#include <bits/stdc++.h>
#include <limits>
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

struct pair_hash {
  inline size_t operator()(const pair<int, int> &v) const {
    return hash<int>{}(v.first) ^ (hash<int>{}(v.second) << 1);
  }
};

template <typename S, typename T> class PairHash {
public:
  inline size_t operator()(const pair<S, T> &v) const {
    return hash<S>{}(v.first) ^ (hash<T>{}(v.second) << 1);
  }
};

int main() {
  int n;
  cin >> n;
  vector<ll> dv(n);
  rep(i, n) cin >> dv[i];
  sort(begin(dv), end(dv), greater<ll>());
  vector<ll> lv(2), cv(2), kv(2);
  rep(i, 2) cin >> lv[i] >> cv[i] >> kv[i];

  unordered_set<pair<int, int>, PairHash<int, int>> cands = {{0, 0}};

  rep(i, n) {
    vector<pair<int, int>> delta;
    rep(j, kv[0] + 1) {
      ll d = dv[i] - j * lv[0];
      if (d > 0) {
        int k = (d + lv[1] - 1) / lv[1];
        delta.push_back({j, k});
      } else {
        delta.push_back({j, 0});
        break;
      }
    }
    unordered_set<pair<int, int>, PairHash<int, int>> new_cands;
    for (auto [a, b] : cands) {
      for (auto [c, d] : delta) {
        if (a + c <= kv[0] && b + d <= kv[1]) {
          new_cands.insert({a + c, b + d});
        }
      }
    }
    cands = new_cands;
  }

  ll res = numeric_limits<ll>::max();
  for (auto [a, b] : cands)
    res = min(res, cv[0] * (ll)a + cv[1] * (ll)b);
  if (res == numeric_limits<ll>::max())
    res = -1;
  cout << res << endl;

  return 0;
}
