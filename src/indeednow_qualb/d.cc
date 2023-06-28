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
  ll n, c;
  cin >> n >> c;
  vector<vector<int>> av(c + 1);
  rep(i, n) {
    int a;
    cin >> a;
    av[a].push_back(i);
  }
  for (int i = 1; i <= c; i++) {
    ll res = n * (n + 1ll) / 2ll;
    vector<int> temp = {-1};
    rep(j, av[i].size()) temp.push_back(av[i][j]);
    temp.push_back(n);
    for (int j = 1; j < int(temp.size()); j++) {
      ll size = temp[j] - temp[j-1] - 1;
      res -= size * (size+1ll) / 2ll;
    }
    cout << res << endl;
  }
  return 0;
}
#endif
