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

// #ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<vector<int>> am(n, vector<int>(n, 0)), res(n, vector<int>(n));
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, n) { am[i][j] = res[i][j] = s[j] == '1'; }
  }
  rep(i, n - 1) {
    res[0][i + 1] = am[0][i];
    res[i + 1][n - 1] = am[i][n - 1];
    res[n - 1][i] = am[n - 1][i + 1];
    res[i][0] = am[i + 1][0];
  }

  rep(i, n) {
    rep(j, n) { cout << res[i][j]; }
    cout << endl;
  }

  return 0;
}
// #endif
