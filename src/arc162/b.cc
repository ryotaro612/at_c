#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  os << "[";
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
  return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
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
  vector<int> pv(n);
  rep(i, n) cin >> pv[i];

  vector<pair<int, int>> items;
  while (true) {
    bool ok = true;
    int i = 0;
    for (; i < n; i++) {
      if (pv[i] != i + 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "Yes" << endl << items.size() << endl;
      for (auto [a, b] : items)
        cout << a << " " << b << endl;
      return 0;
    }
    int j = i + 1;
    for (; j < n; j++) {
      if (pv[j] == i + 1)
        break;
    }
    debug(i, j);
    if (j < n - 1) {
      items.push_back({j + 1, i});
      int a = pv[j], b = pv[j + 1];
      pv.erase(pv.begin() + j, pv.begin() + j + 2);
      pv.insert(pv.begin() + i, a);
      pv.insert(pv.begin() + i + 1, b);
      debug(make_pair(j + 1, i));
      debug(pv);
    } else if (i < n - 2) {
      items.push_back({n - 1, n - 3});
      int a = pv[n - 1], b = pv[n - 2], c = pv[n - 3];
      pv[n - 3] = b;
      pv[n - 2] = a;
      pv[n - 1] = c;
      debug(make_pair(n - 1, n - 3));
      debug(pv);
    } else {
      cout << "No" << endl;
      return 0;
    }
  }

  return 0;
}
// #endif
