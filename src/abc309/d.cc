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

vector<int> calc_dist(int start, vector<vector<int>> &g) {
  queue<int> que;
  vector<int> d(g.size(), 1 << 30);
  d[start] = 0;
  que.push(start);
  while (que.size()) {
    int node = que.front();
    que.pop();
    for (int neighbor : g[node]) {
      if (d[neighbor] > d[node] + 1) {
        d[neighbor] = d[node] + 1;
        que.push(neighbor);
      }
    }
  }
  return d;
}

// #ifdef ONLINE_JUDGE
int main() {
  int n1, n2, m;
  cin >> n1 >> n2 >> m;
  vector<vector<int>> g(n1 + n2);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  int res = 0, temp = 0;
  vector<int> d = calc_dist(0, g);

  rep(i, n1) { temp = max(temp, d[i]); }
  res += temp;
  temp = 0;
  d = calc_dist(n1 + n2 - 1, g);
  for (int i = n1; i < n1 + n2; i++) {
    temp = max(temp, d[i]);
  }
  res += temp;
  cout << res + 1 << endl;

  return 0;
}
// #endif
