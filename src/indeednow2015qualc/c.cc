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

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1, vector<int>());
  rep(_, n - 1) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> res;
  vector<bool> visit(n+1, false);
  set<int> que;
  que.insert(1);
  while (que.size()) {
    int node = *que.begin();
    que.erase(que.begin());
    visit[node] = true;
    res.push_back(node);
    for (int neighbor : g[node]) {
      if (!visit[neighbor]) {
        que.insert(neighbor);
      }
    }
  }
  rep(i, res.size()) { cout << res[i] << " \n"[i == int(res.size()) - 1]; }
  return 0;
}
#endif
