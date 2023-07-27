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
void yes() {
  cout << "YES\n";
  exit(0);
}
void no() {
  cout << "NO\n";
  exit(0);
}

bool sub(string &a_diff, string &b_diff, bool skip, int count) {
  if (count == 0)
    return a_diff == b_diff;
  if (skip && sub(a_diff, b_diff, skip, count - 1))
    return true;
  rep(i, size(a_diff) - 1) {
    for (int j = i + 1; j < (int)size(a_diff); j++) {
      swap(a_diff[i], a_diff[j]);
      if (sub(a_diff, b_diff, skip, count - 1))
        return true;
      swap(a_diff[i], a_diff[j]);
    }
  }
  return false;
}

int main() {
  string a, b, a_diff, b_diff;
  cin >> a >> b;
  vector<int> freq_a(26, 0), freq_b(26, 0);
  bool skip = false;
  rep(i, size(a)) {
    freq_a[a[i] - 'a']++;
    freq_b[b[i] - 'a']++;
    if (freq_b[b[i] - 'a'] > 1)
      skip = true;
    if (a[i] != b[i]) {
      a_diff.push_back(a[i]);
      b_diff.push_back(b[i]);
    }
  }
  if (size(a_diff) > 6)
    no();
  rep(i, 26) if (freq_a[i] != freq_b[i]) no();
  debug("skip", skip);
  if (sub(a_diff, b_diff, skip, 3))
    yes();
  else
    no();
}
