#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool sub(vector<int> &av, vector<int> &bv, int start, int bound) {
  int n = av.size();
  int pos = start;

  rep(i, n) {
    pos += av[i];

    if (!(0 < pos && pos <= bound))
      return true;

    if ((0 < pos + bv[i] && pos + bv[i] <= bound)) {
      pos += bv[i];
    }
    // cout << pos << endl;
  }
  return false;
}

// #ifdef ONLINE_JUDGE
int main() {
  int h, w, n, sr, sc;
  string s, t;
  cin >> h >> w >> n >> sr >> sc >> s >> t;
  vector<tuple<char, char, int, int, int>> patterns = {{'U', 'D', -1, sr, h},
                                                       {'R', 'L', 1, sc, w},
                                                       {'D', 'U', 1, sr, h},
                                                       {'L', 'R', -1, sc, w}};

  for (auto [f, b, delta, start, bound] : patterns) {
    vector<int> av(n, 0), bv(n, 0);
    rep(i, n) {
      if (s[i] == f) {
        av[i] = delta;
      }
      if (t[i] == b)
        bv[i] = -delta;
    }
    // cout << f << " " << b << endl;
    if (sub(av, bv, start, bound)) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
// #endif
