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

  int n, res = 0;
  cin >> n;
  vector<string> sm(n);
  rep(i, n) cin >> sm[i];
  rep(shift, n) {

    vector<vector<char>> alter(n, vector<char>(n, ' '));
    rep(r, n) {
      rep(c, n) { alter[r][(c + shift) % n] = sm[r][c]; }
    }
    bool ok = true;
    rep(r, n) {
      rep(c, n) {
        if (alter[r][c] != alter[c][r])
          ok = false;
      }
    }
    if (ok)
      res++;
  }
  cout << res * n << endl;
  return 0;
}
#endif
