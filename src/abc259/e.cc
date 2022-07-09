#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> mv(n);
  vector<vector<ll>> pv, ev;
  rep(i, n) {
    cin >> mv[i];
    pv.push_back(vector<ll>(mv[i]));
    ev.push_back(vector<ll>(mv[i]));
    rep(j, mv[i]) { cin >> pv[i][j] >> ev[i][j]; }
  }
  map<ll, pair<ll, set<int>>> primes;
  rep(i, n) {
    rep(j, mv[i]) {
      ll base = pv[i][j];
      ll exp = ev[i][j];
      if (primes.find(base) == primes.end() || primes[base].first < exp) {
        primes[base] = {exp, {i}};
      } else if (primes[base].first == exp) {
        primes[base].second.insert(i);
      }
    }
  }
  int res = 0;
  rep(i, n) {
    rep(j, mv[i]) {
      ll base = pv[i][j], exp = ev[i][j];
      if (primes[base].first == exp && primes[base].second.size() == 1) {
        res++;
        break;
      }
    }
  }
  cout << min(res + 1, n) << endl;
  return 0;
}
#endif
