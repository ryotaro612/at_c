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

void calc_depth(vector<vector<int>> &g, int node, vector<int> &depth) {
  for (auto e : g[node]) {
    if (depth[e] == -1)
      continue;
    depth[e] = depth[node] + 1;
    calc_depth(g, e, depth);
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> av(n - 1), bv(n - 1);
  rep(i, n - 1) {
    cin >> av[i] >> bv[i];
    av[i]--;
    bv[i]--;
  }
  vector<int> vv(k);
  rep(i, k) {
    cin >> vv[i];
    vv[i]--;
  }
  vector<set<int>> g(n);
  rep(i, n - 1) {
    g[av[i]].insert(bv[i]);
    g[bv[i]].insert(av[i]);
  }

  set<int> st(begin(vv), end(vv));
  queue<int> que;
  rep(i, n) {
    if (g[i].size() == 1) {
      que.push(i);
    }
  }

  while (que.size()) {
    int node = que.front();
    que.pop();
    if (st.contains(node))
      continue;
    int parent = *begin(g[node]);
    g[node].clear();
    g[parent].erase(node);
    if (g[parent].size() == 1)
      que.push(parent);
  }

  int res = k;
  int temp = 0;
  rep(i, n) {
    if (g[i].size())
      temp++;
  }
  cout << max(res, temp) << endl;

  return 0;
}
