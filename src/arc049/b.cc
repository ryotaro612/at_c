#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ld sub(vector<ld> xv, vector<ld> cv) {
  int n = xv.size();
  vector<pair<ld, ld>> xcv(n);
  rep(i, n) { xcv[i] = {xv[i], cv[i]}; }
  sort(xcv.begin(), xcv.end());
  ld res = numeric_limits<ld>::max();
  for (int i = 0; i < n - 1; i++) {
    ld lb = xcv[i].first, ub = xcv[i + 1].first;

    while (ub - lb > 0.00000000001) {
      ld lmid = (2.0 * lb + ub) / 3.0;
      ld rmid = (lb + 2.0 * ub) / 3.0;
      ld time_l = 0, time_r = 0;
      rep(j, n) {
        time_l = max(time_l, abs(xcv[j].first - lmid) * xcv[j].second);
        time_r = max(time_r, abs(xcv[j].first - rmid) * xcv[j].second);
      }
      if (time_l < time_r)
        ub = rmid;
      else
        lb = lmid;
    }
    ld temp = 0;
    rep(j, n) { temp = max(temp, abs(xcv[j].first - lb) * xcv[j].second); }
    res = min(res, temp);
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ld> xv(n), yv(n), cv(n);
  rep(i, n) cin >> xv[i] >> yv[i] >> cv[i];

  cout << fixed << setprecision(12) << max(sub(xv, cv), sub(yv, cv)) << endl;
  return 0;
}
#endif
