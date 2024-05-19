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

bool solve(ll mask, vector<ll> &av, vector<ll> &bv, map<ll, bool> &cache) {
  if (cache.contains(mask))
    return cache[mask];
  int n = av.size();
  vector<int> exist;
  rep(i, n) {
    if (mask & (1 << i))
      exist.push_back(i);
  }

  rep(i, exist.size()) {
    for (int j = i + 1; j < (int)exist.size(); j++) {
      if (av[exist[i]] == av[exist[j]] || bv[exist[i]] == bv[exist[j]]) {
        if (!solve(((mask ^ (1 << exist[i])) ^ (1 << exist[j])), av, bv,
                   cache)) {
          return cache[mask] = true;
        }
      }
    }
  }
  return cache[mask] = false;
}
int main() {
  ll n;
  cin >> n;
  vector<ll> av(n), bv(n);
  rep(i, n) cin >> av[i] >> bv[i];

  map<ll, bool> cache;
  if (solve((1ll << n) - 1ll, av, bv, cache)) {
    cout << "Takahashi\n";
  } else
    cout << "Aoki\n";
  return 0;
}
