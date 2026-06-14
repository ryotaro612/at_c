#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
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

ll traverse(int node, int parent, vector<set<int>> &g,
            map<pair<int, int>, ll> &best) {
  dbg(node, parent);
  if (best.count({node, parent})) {
    return best[{node, parent}];
  }
  vector<ll> cand;

  for (auto &child : g[node]) {
    if (child == parent)
      continue;
    cand.push_back(traverse(child, node, g, best));
  }
  ll res = 1ll;

  if (cand.size()) {
    sort(cand.rbegin(), cand.rend());
    res += +cand[0] + cand[1] + cand[2];
    if (parent == -1) {
      res += cand[3];
    }
  }
  best[{node, parent}] = res;
  return res;
}

int main() {
  // fとしてふるまう
  int n;
  cin >> n;
  vector<int> av(n - 1), bv(n - 1);
  vector<set<int>> g(n);
  rep(i, n - 1) {
    cin >> av[i] >> bv[i];
    g[--av[i]].insert(--bv[i]);
    g[bv[i]].insert(av[i]);
  }
  int new_node = n;
  rep(i, n - 1) {
    if (g[av[i]].size() < 4 && g[bv[i]].size() < 4) {
      g[av[i]].erase(bv[i]);
      g[bv[i]].erase(av[i]);
    } else if (g[av[i]].size() < 4 && g[bv[i]].size() >= 4) {
      g[av[i]].erase(bv[i]);
      g[bv[i]].erase(av[i]);
      g[bv[i]].insert(new_node++);
      g.push_back({bv[i]});
    } else if (g[av[i]].size() >= 4 && g[bv[i]].size() < 4) {
      g[av[i]].erase(bv[i]);
      g[bv[i]].erase(av[i]);
      g[av[i]].insert(new_node++);
      g.push_back({av[i]});
    }
  }
  dbg(g);

  ll res = -1;
  map<pair<int, int>, ll> best;
  rep(i, n) { res = max(res, traverse(i, -1, g, best)); }
  if (res < 5) {
    res = -1;
  }
  cout << res << endl;

  return 0;
}
