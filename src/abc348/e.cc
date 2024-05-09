#include <algorithm>
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

ll prepare(int node, int parent, vector<vector<int>> &g, vector<ll> &cv,
           vector<ll> &c_sum) {
  c_sum[node] = cv[node];
  ll res = 0;

  for (auto child : g[node]) {
    if (parent == child)
      continue;
    res += prepare(child, node, g, cv, c_sum);
    c_sum[node] += c_sum[child];
    res += c_sum[child];
  }
  return res;
}

void traverse(int node, int parent, vector<vector<int>> &g, vector<ll> &cv,
              vector<ll> &c_sum, vector<ll> &results, ll c_total) {

  for (auto &child : g[node]) {
    if (child == parent)
      continue;
    results[child] = results[node] - c_sum[child] + (c_total - c_sum[child]);
    traverse(child, node, g, cv, c_sum, results, c_total);
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<ll> cv(n), c_sum(n, 0), results(n, 0);
  ll c_total = 0;
  rep(i, n) {
    cin >> cv[i];
    c_total += cv[i];
  }

  results[0] = prepare(0, -1, g, cv, c_sum);
  dbg(c_sum);
  dbg(results);
  traverse(0, -1, g, cv, c_sum, results, c_total);

  cout << *min_element(begin(results), end(results)) << endl;
  return 0;
}
