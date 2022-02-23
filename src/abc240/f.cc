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
    //    cout << "=== case====" << endl;
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
        // cout << "3bun " << i << endl;
        ll lb = -1ll, ub = c.yv[i];
        while (ub - lb > 2ll) {
          ll mid1 = (ub + lb) / 2ll;
          ll mid2 = mid1 + 1ll;
          ll delta1 =
              bv[i - 1] * mid1 + (c.xv[i] + (c.xv[i] * mid1)) * mid1 / 2ll;
          ll delta2 =
              bv[i - 1] * mid2 + (c.xv[i] + (c.xv[i] * mid2)) * mid2 / 2ll;
          if (delta1 < delta2)
            lb = mid1;
          else // delta1 >=delta2
            ub = mid2;
        }

        res_e = max(av[i - 1] + bv[i - 1] * (lb + 1) +
                        (c.xv[i] + (c.xv[i] * (lb + 1))) * (lb + 1) / 2ll,
                    res_e);
        // cout << "found: " << av[i - 1] << " " << bv[i - 1] << " " << c.xv[i]
        //      << " " << c.yv[i] << lb + 1 << " " << res_e << endl;
      }
    }
    res.push_back(res_e);
  }
  return res;
}

#ifdef ONLINE_JUDGE
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
#endif

// 10 472

// -4 12
// 1 29
// 2 77
// -1 86
// 0 51
// 3 81
// 3 17
// -2 31
// -4 65
// 4 23
