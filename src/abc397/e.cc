#include <algorithm>
#include <cassert>
#include <cmath>
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

int traverse(int node, int parent, vector<vector<int>> &g, int k) {
  dbg(node);
  vector<int> counts;
  for (int child : g[node]) {
    if (child == parent)
      continue;
    int n_child = traverse(child, node, g, k);
    if (n_child < 0) {
      dbg(-1);
      return -1;
    }

    if (n_child) {
      counts.push_back(n_child);
    }
  }
  if (counts.size() > 2) {
    dbg(-1);
    return -1;
  }
  if (counts.size() == 2) {
    if ((counts[0] + counts[1] + 1) % k) {
      dbg(-1);
      return -1;
    } else {
      dbg(0);
      return 0;
    }
  }
  if (counts.size() == 1) {
    dbg((counts[0] + 1) % k);
    return (counts[0] + 1) % k;
  }
  dbg(1 % k);
  return 1 % k;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << "Yes" << endl;
    return 0;
  }
  vector<vector<int>> g(n * k);
  queue<int> que;
  rep(i, n * k - 1) {
    int u, v;
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }

  int res = traverse(0, -1, g, k);
  dbg(res);
  if (res % k == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
