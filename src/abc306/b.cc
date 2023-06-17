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

#ifdef ONLINE_JUDGE
int main() {

  ull res = 0ll, offset = 1ull;
  rep(i, 64) {
    int a;
    cin >> a;
    if (a) {
      res += offset;
    }
    offset <<= 1ull;
  }
  cout << res << endl;
  return 0;
}
#endif
