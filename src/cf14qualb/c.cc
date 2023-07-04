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

vector<int> count_letters(string &s) {
  vector<int> cnt(26, 0);
  for (auto c : s) {
    cnt[c - 'A']++;
  }
  return cnt;
}

// #ifdef ONLINE_JUDGE
int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  vector<int> cnt1 = count_letters(s1), cnt2 = count_letters(s2),
              cnt3 = count_letters(s3);

  int a = 0;
  rep(i, 26) {
    if (cnt1[i] + cnt2[i] < cnt3[i]) {
      cout << "NO\n";
      return 0;
    }
    a += min(cnt1[i], cnt3[i]);
  }
  if (a < int(s1.size()) / 2) {
    cout << "NO\n";
    return 0;
  }
  rep(i, 26) { a -= min(cnt2[i], cnt3[i]) - (cnt3[i] - min(cnt1[i], cnt3[i])); }
  if (a <= int(s1.size()) / 2)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
// #endif
