#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dfs(ll n, ll m, ll q, vector<ll> &a, vector<vector<ll>> &qa) {
  if ((ll)a.size() == n) {
    ll res = 0;
    for (ll i = 0; i < q; i++) {
      if (a[qa[i][1] - 1] - a[qa[i][0] - 1] == qa[i][2]) {
        res += qa[i][3];
      }
    }
    return res;
  }

  ll res = 0;
  ll begin = a.size() == 0 ? 1 : a.back();
  for (ll i = begin; i <= m; i++) {
    a.push_back(i);
    res = max(dfs(n, m, q, a, qa), res);
    a.pop_back();
  }
  return res;
}

ll solve(ll n, ll m, ll q, vector<vector<ll>> qa) {
  vector<ll> a;
  return dfs(n, m, q, a, qa);
}
/*
int main() {
  ll n, m, q;
  cin >> n >> m >> q;
  vector<vector<ll>> qa(q);
  for (ll i = 0; i < q; i++) {
    qa[i] = vector<ll>(4);
    cin >> qa[i][0] >> qa[i][1] >> qa[i][2] >> qa[i][3];
  }
  cout << solve(n, m, q, qa);
}
*/