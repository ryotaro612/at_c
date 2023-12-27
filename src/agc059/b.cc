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
  int t;
  cin >> t;
  rep(_, t) {
    int n;
    cin >> n;
    vector<int> cv(n);
    map<int, int> freq;
    rep(i, n) {
      cin >> cv[i];
      freq[cv[i]]++;
    }
    int k = freq.size();
    if (k == 1 || k == 2 || n < (2 * k - 2)) {
      sort(begin(cv), end(cv));
      rep(i, n) cout << cv[i] << " \n"[i == n - 1];
      continue;
    }
    dbg("doge");
    map<int, int> deg;
    int rest = 2 * k - 2;
    for (auto entry : freq) {
      deg[entry.first] = 1;
      rest--;
    }
    for (auto entry : freq) {
      int delta = min(entry.second - deg[entry.first], rest);
      deg[entry.first] += delta;
      rest -= delta;
    }
    set<pair<int, int>> order;
    for (auto [node, deg_v] : deg) {
      order.insert({deg_v, node});
    }
    map<int, vector<int>> g;

    while (order.size()) {
      auto [f, node] = *begin(order);
      auto [other_freq, other_node] = *rbegin(order);
      g[node].push_back(other_node);
      g[other_node].push_back(node);
      order.erase({f, node});
      order.erase({other_freq, other_node});
      if (f > 1)
        order.insert({f - 1, node});
      if (other_freq > 1)
        order.insert({other_freq - 1, other_node});
    }
    for (auto [k, v]: g) {
      dbg(k, v);
    }
    vector<int> res;
    function<void(int, int)> func = [&](int node, int parent) {
      int cnt = 0;
      res.push_back(node);
      cnt++;
      for (auto child : g[node]) {
        if (child != parent) {
          func(child, node);
          res.push_back(node);
          cnt++;
        }
      }
      while (cnt++ < freq[node]) {
        res.push_back(node);
      }
    };
    func(begin(freq)->first, -1);

    rep(i, n) cout << res[i] << " \n"[i == n - 1];
    continue;
  }
  return 0;
}
