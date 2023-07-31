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
// g++ -fdiagnostics-color=always -g -O0 --std=c++17 -Wall
// -fsanitize=undefined,address
int main() {
  int q;
  ll l;
  cin >> q >> l;
  vector<pair<ll, ll>> stack;
  ll size = 0;
  rep(_, q) {
    string ord;
    cin >> ord;
    if (ord == "Push") {
      ll n, m;
      cin >> n >> m;
      stack.push_back({n, m});
      size += n;
      if (size > l) {
        cout << "FULL\n";
        return 0;
      }
    } else if (ord == "Pop") {
      ll n;
      cin >> n;
      if (size < n) {
        cout << "EMPTY\n";
        return 0;
      }
      size -= n;
      while (n) {
        pair<ll, ll> e = stack.back();
        stack.pop_back();
        ll delta = min(e.first, n);
        n -= delta;
        e.first -= delta;
        if (e.first)
          stack.push_back(e);
      }
    } else if (ord == "Top") {
      debug(stack);
      if (size)
        cout << stack.back().second << endl;
      else {
        cout << "EMPTY\n";
        return 0;
      }
    } else {
      cout << size << endl;
    }
  }
  cout << "SAFE\n";
  return 0;
}
