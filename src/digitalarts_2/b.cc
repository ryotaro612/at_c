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
  string s;
  cin >> s;
  if (s == "a" || s == "zzzzzzzzzzzzzzzzzzzz") {
    cout << "NO\n";
    return 0;
  }
  int n = size(s);
  if (n > 1 && s[0] != 'z') {
    s[0]++;
    if (s[n - 1] == 'a')
      s.pop_back();
    else
      s[n - 1]--;
  } else {
    s[0]--;
    bool ok = false;
    for (int i = 1; i < n; i++) {
      if (s[i] != 'z') {
        s[i]++;
        ok = true;
        break;
      }
    }
    if (!ok)
      s.push_back('a');
  }
  cout << s << endl;
  return 0;
}
