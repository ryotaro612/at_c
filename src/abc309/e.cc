#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  if (v.size() == 0) {
    os << "]";
    return os;
  }
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
  return os;
}

void debug_() { cout << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif

void expand(int node, vector<vector<int>> &g, map<int, int> &insure,
            vector<bool> &ok) {
  if (insure[node]) {
    for (int child : g[node]) {
      ok[child] = true;
    }
  }
}

// #ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    int p;
    cin >> p;
    g[p - 1].push_back(i + 1);
  }
  vector<bool> ok(n, false);
  map<int, int> insure;
  rep(_, m) {
    int x, y;
    cin >> x >> y;
    ok[--x] = true;
    insure[x] = max(insure[x], y);
  }
  rep(i, n) {
    if (insure[i] == 0)
      continue;
    for (int child : g[i]) {
      ok[child] = true;
      insure[child] = max(insure[child], insure[i] - 1);
    }
  }
  int res = 0;
  for (auto e : ok) {
    if (e)
      res++;
  }
  cout << res << endl;
  return 0;
}
// #endif
