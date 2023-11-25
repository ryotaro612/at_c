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

struct A {
  map<ll, int> freq;
  set<pair<ll, ll>> ranges;
  A() {}

  void add(ll a) {
    freq[a]++;
    if (freq[a] > 1ll)
      return;
    auto iter = ranges.lower_bound({a, numeric_limits<ll>::max()});
    if (freq[a - 1ll]) {
      if (freq[a + 1ll]) {
        auto forward = *iter;
        auto backward = *prev(iter);
        pair<ll, ll> p = {backward.first, forward.second};
        ranges.erase(forward);
        ranges.erase(backward);
        ranges.insert(p);
      } else {
        auto backward = *prev(iter);
        ranges.erase(backward);
        ranges.insert({backward.first, a+1ll});
      }
    } else {
      if (freq[a + 1ll]) {
        auto p = *iter;
        ranges.erase(iter);
        ranges.insert({a, p.second});
      } else {
        ranges.insert({a, a + 1ll});
      }
    }
  }
  void del(ll a) {
    freq[a]--;
    if (freq[a])
      return;

    auto iter = prev(ranges.lower_bound({a, numeric_limits<ll>::max()}));
    auto p = *iter;
    ranges.erase(iter);
    if (p.first + 1 == p.second)
      return;
    if (p.first == a) {
      ranges.insert({a + 1ll, p.second});
    } else if (a < p.second - 1ll) {
      ranges.insert({p.first, a});
      ranges.insert({a + 1, p.second});
    } else {
      ranges.insert({p.first, p.second - 1ll});
    }
  }

  ll solve() {
    if (freq[0]) {
      return begin(ranges)->second;
    } else {
      return 0;
    }
  }

  void debug() {
    for(auto e: ranges) {
      dbg(e.first, e.second);
    }
  }
};
int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> av(n);
  A solver;
  rep(i, n) {
    cin >> av[i];
    solver.add(av[i]);
  }
  rep(_, q) {
    ll i, x;
    cin >> i >> x;
    solver.del(av[--i]);
    solver.debug();    
    solver.add(x);
    //dbg("---");
    solver.debug();    
    av[i] = x;
    //dbg("====");
    cout << solver.solve() << endl;
  }

  return 0;
}
