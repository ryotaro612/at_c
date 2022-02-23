#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Case {
  int n;
  ll m;
  vector<ll> xv;
  vector<ll> yv;
  Case(int n, ll m, vector<ll> &xv, vector<ll> &yv)
      : n(n), m(m), xv(xv), yv(yv) {}
};

vector<ll> solve(vector<Case> &cases) {
  vector<ll> res;
  for (Case c : cases) {
    // cout << "=== case====" << endl;
    vector<ll> bv(c.n, 0ll);
    rep(i, c.n) {
      if (0 < i) {
        bv[i] += bv[i - 1];
      }
      bv[i] += c.xv[i] * c.yv[i];
    }
    // cout << "bv: ";
    // rep(j, c.n) { cout << bv[j] << " "; }
    // cout << endl;
    vector<ll> progress(c.n, 0ll);
    rep(i, c.n) {
      progress[i] = (c.xv[i] + (c.xv[i] * c.yv[i])) * c.yv[i] / 2ll;
    }
    // cout << "progress: ";
    // rep(j, c.n) cout << progress[j] << " ";
    // cout << endl;
    vector<ll> av(c.n, 0ll);
    rep(i, c.n) {
      av[i] = progress[i];
      if (0 < i) {
        av[i] += av[i - 1];
        av[i] += bv[i - 1] * c.yv[i];
      }
    }
    // cout << "av: ";
    // rep(j, c.n) cout << av[j] << " ";
    // cout << endl;
    ll res_e = max(c.xv[0], *max_element(av.begin(), av.end()));

    for (int i = 1; i < c.n; i++) {
      if (bv[i - 1] > 0 && c.xv[i] < 0) {
        ll lb = -1ll, ub = c.m;
        while (ub - lb > 1ll) {
          ll mid = (ub + lb) / 2ll;
          ll delta = bv[i - 1] * mid + (c.xv[i] + (c.xv[i] * mid)) * mid / 2ll;
          if (delta < 0)
            ub = mid;
          else // delta >= 0
            lb = mid;
        }
        res_e = max(av[i - 1] + bv[i - 1] * lb +
                        (c.xv[i] + (c.xv[i] * lb)) * lb / 2ll,
                    res_e);
      } else if (bv[i - 1] < 0 && c.xv[i] > 0) {
      }
    }
    res.push_back(res_e);
  }
  return res;
}

//#ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  vector<Case> cases;
  rep(i, t) {
    ll n, m;
    cin >> n >> m;
    vector<ll> xv(n), yv(n);
    rep(j, n) { cin >> xv[j] >> yv[j]; }
    cases.push_back(Case(n, m, xv, yv));
  }
  vector<ll> res = solve(cases);
  for (auto e : res)
    cout << e << endl;
  return 0;
}
//#endif
