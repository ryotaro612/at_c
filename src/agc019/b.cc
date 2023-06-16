#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  cout << "[";
  string s[2] = {", ", "]"};
  rep(i, v.size()) { cout << v[i] << s[i == int(v.size()) - 1]; }
  return os;
}

int letters[26];
#ifdef ONLINE_JUDGE
int main() {
  string a;
  cin >> a;
  ll res = ((ll)a.size()) * (((ll)a.size()) - 1ll) / 2ll + 1ll;
  for (auto c : a) {
    letters[c - 'a']++;
  }
  for (auto c : a) {
    letters[c - 'a']--;
    res -= letters[c - 'a'];
  }
  cout << res << endl;

  return 0;
}
#endif
