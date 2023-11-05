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

void rec(int node, vector<vector<int>> &g, vector<int> &res) {
  for (auto child : g[node]) {
    if (node == child)
      continue;
    if (res[child] == -1) {
      res[child] = 1 - res[node];
      rec(child, g, res);
    }
    else if (res[child] == res[node]) {
      cout << "No\n";
      exit(0);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> av(m), bv(m);
  rep(i, m) cin >> av[i];
  rep(i, m) cin >> bv[i];
  rep(i, m) {
    if(av[i] == bv[i]){
      cout << "No\n";
      return 0;
    }
    g[--av[i]].push_back(--bv[i]);
    g[bv[i]].push_back(av[i]);
  }
  vector<int> res(n, -1);
  rep(i, n) {
    if (res[i] == -1)
      res[i] = 1;
    rec(i, g, res);
  }
  cout << "Yes\n";

  return 0;
}
