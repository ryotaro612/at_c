#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  /*
    y が同じペアをつくる
    x1 < x2 であれば s[1] R s[2]がL
    x1 > x2 であれば
    // rrr llllであればいい
   */
  int n;
  cin >> n;
  vector<ll> xv(n), yv(n);
  rep(i, n) { cin >> xv[i] >> yv[i]; }
  string s;
  cin >> s;
  unordered_map<ll, set<pair<ll, int>>> coordinate;
  rep(i, n) { coordinate[yv[i]].insert({xv[i], i}); }
  for (pair<ll, set<pair<ll, int>>> kv : coordinate) {
    vector<char> a;
    for (pair<ll, int> e : kv.second) {
      a.push_back(s[e.second]);
    }
    // for(auto c: a) {
    //   cout << c;
    // }
    // cout << endl;
    int first_r = -1;
    for (int i = 0; i < (int)a.size(); i++) {
      if (a[i] == 'R') {
        first_r = i;
        break;
      }
    }
    if (first_r >= 0) {
      for (int i = first_r + 1; i < (int)a.size(); i++) {
        if (a[i] == 'L') {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;

  return 0;
}
#endif
