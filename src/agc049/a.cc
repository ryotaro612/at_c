#include <bits/stdc++.h>
#include <iomanip>
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
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, s.size()) {
      if (s[j] == '1') {
        g[i].push_back(j);
      }
    }
  }
  vector<ld> count(n, 0);
  dbg("doge");
  rep(i, n) {
    queue<int> que;
    vector<bool> visited(n, false);
    visited[i] = true;
    que.push(i);
    while (que.size()) {
      int node = que.front();
      que.pop();
      for (auto neighbor : g[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          que.push(neighbor);
        }
      }
    }
    rep(j, n) {
      if (visited[j]) {
        count[j]++;
      }
    }
  }
  ld res = 0;
  for (auto e : count) {
    res += (ld)1.0 / e;
  }
  cout << fixed << setprecision(12) << res << endl;
  return 0;
}
