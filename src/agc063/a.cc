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
  int n;
  string s;
  cin >> n >> s;
  vector<int> pos_a, pos_b;
  for (int i = n; i >= 0; i--) {
    if (s[i] == 'A')
      pos_a.push_back(i);
    else
      pos_b.push_back(i);
  }
  rep(i, n) {
    if (i % 2 == 0) { // aliceの番
      if (size(pos_b))
        pos_b.pop_back();
      else
        pos_a.pop_back();
    } // Bobの番
    else {
      if (size(pos_a))
        pos_a.pop_back();
      else
        pos_b.pop_back();
    }
    debug(i, pos_a, pos_b);
    if (size(pos_a)) {
      if (size(pos_b)) {
        if (pos_a.back() < pos_b.back())
          cout << "Alice\n";
        else
          cout << "Bob\n";
      } else
        cout << "Alice\n";
    } else {
      cout << "Bob\n";
    }
  }
  return 0;
}
