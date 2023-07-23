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
int pa[100], ca[100];
bool fm[100][100];

bool upper(int j, int n) {
  rep(i, n) {
    if (j == i)
      continue;
    if (pa[i] < pa[j])
      continue;
    bool ok = true;
    rep(k, 100) {
      if (fm[i][k] && !fm[j][k])
        ok = false;
    }
    if (!ok)
      continue;
    if (pa[i] > pa[j])
      return true;
    rep(k, 100) {
      if (!fm[i][k] && fm[j][k])
        return true;
    }
  }
  return false;
}

// #ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  rep(i, n) {
    cin >> pa[i] >> ca[i];
    rep(_, ca[i]) {
      int f;
      cin >> f;
      fm[i][--f] = true;
    }
  }
  rep(i, n) {
    if (upper(i, n)) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}
// #endif
