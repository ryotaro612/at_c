#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

int find_root(vector<int> &par, int i) {
  if (par[i] < 0)
    return i;
  return par[i] = find_root(par, par[i]);
}

bool is_same_group(vector<int> &par, int a, int b) {
  return find_root(par, a) == find_root(par, b);
}

void unite(vector<int> &par, int a, int b) {
  if (is_same_group(par, a, b))
    return;
  int root_a = find_root(par, a);
  int root_b = find_root(par, b);

  if (par[root_a] < par[root_b]) {
    par[root_a] += par[root_b];
    par[root_b] = root_a;
  } else {
    par[root_b] += par[root_a];
    par[root_a] = root_b;
  }
}

ll solve(int n, vector<int> &xv, vector<ll> &cv) {
  vector<int> par(n, -1);
  ll res = 0ll;
  rep(i, n) xv[i]--;
  rep(i, n) {
    if (!is_same_group(par, i, xv[i])) {
      unite(par, i, xv[i]);
      continue;
    }

    int start = i;
    int cur = i;
    ll cost = cv[start];
    // cout << start << " " << cost << endl;
    while (true) {
      cur = xv[cur];
      // cout << "cur" << cur << endl;
      cost = min(cost, cv[cur]);
      if (xv[cur] == start) {
        break;
      }
    }
    res += cost;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> xv(n);
  rep(i, n) cin >> xv[i];
  vector<ll> cv(n);
  rep(i, n) cin >> cv[i];
  cout << solve(n, xv, cv) << endl;
  return 0;
}
#endif
