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

int time_diff(int a, int b) {
  if (a > b)
    swap(a, b);
  return min(b - a, 24 - b + a);
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> found(13, 0);
  found[0] = 1;
  vector<int> dv = {0};
  int base = 12;
  rep(i, n) {
    int d;
    cin >> d;
    if (found[d] == 1) {
      if (d == 12 || d == 0) {
        cout << "0\n";
        return 0;
      }
      base = min(base, time_diff(d, 24 - d));
    } else if (found[d] == 2) {
      cout << "0\n";
      return 0;
    } else {
      dv.push_back(d);
    }
    found[d]++;
  }
  int s = 0;

  rep(mask, 1 << dv.size()) {
    vector<int> pattern;
    rep(i, dv.size()) {
      if (found[dv[i]] == 1) {
        if (mask & (1 << i))
          pattern.push_back(dv[i]);
        else
          pattern.push_back((24 - dv[i]) % 24);
      } else {
        pattern.push_back(dv[i]);
        pattern.push_back((24 - dv[i]) % 24);
      }
    }
    int cand = base;
    rep(i, pattern.size()) {
      for (int j = i + 1; j < int(pattern.size()); j++) {
        int diff = time_diff(pattern[i], pattern[j]);
        // debug(pattern[i], pattern[j], " diff -> ", diff);
        cand = min(cand, diff);
      }
    }

    if (cand == 2) {
      debug("----");
      debug(dv);
      debug(pattern);
    }
    s = max(s, cand);
  }
  cout << s << endl;
  return 0;
}
#endif
