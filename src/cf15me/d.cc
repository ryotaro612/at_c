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

int sub(string first, string second, map<pair<string, string>, int> &memo) {
  if (memo.count({first, second}))
    return memo[{first, second}];
  if (first.size() == 0 || second.size() == 0)
    return memo[{first, second}] = max(first.size(), second.size());
  int res = first.size() + second.size();
  string next_first = string(begin(first) + 1, end(first));
  res = min(res, 1 + sub(next_first, second, memo));
  rep(i, second.size()) {
    if (first[0] == second[i]) {
      res = min(res, i + sub(next_first,
                             string(begin(second) + i + 1, end(second)), memo));
    }
  }
  debug("(", first, second, ")", res);
  return memo[{first, second}] = res;
}

// #ifdef ONLINE_JUDGE
int main() {
  int n;
  string s;
  cin >> n >> s;
  int res = n;
  map<pair<string, string>, int> memo;
  for (int i = 0; i < n; i++) {
    string first(s.begin(), s.begin() + i), second(s.begin() + i, s.end());
    res = min(res, sub(first, second, memo));
    debug(res);
  }
  cout << res << endl;
  return 0;
}
// #endif
