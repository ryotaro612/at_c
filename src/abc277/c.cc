#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

int find_root(int i, vector<int> &par) {
  if (par[i] < 0)
    return i;
  return par[i] = find_root(par[i], par);
}

bool is_same_group(int i, int j, vector<int> &par) {
  return find_root(i, par) == find_root(j, par);
}

void unite(int i, int j, vector<int> &par) {
  if (is_same_group(i, j, par))
    return;
  int root_i = find_root(i, par);
  int root_j = find_root(j, par);

  if (par[root_i] < par[root_j]) {
    par[root_i] += par[root_j];
    par[root_j] = root_i;
  } else {
    par[root_j] += par[root_i];
    par[root_i] = root_j;
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n), bv(n);
  set<ll> st;
  int j = 0;
  map<ll, int> mp;
  rep(i, n) {
    cin >> av[i] >> bv[i];
    st.insert(av[i]);
    st.insert(bv[i]);
    if (mp.find(av[i]) == mp.end())
      mp[av[i]] = j++;
    if (mp.find(bv[i]) == mp.end())
      mp[bv[i]] = j++;
  }
  vector<int> par(st.size(), -1);
  rep(i, n) {
    // cout << i << " " << par.size() << endl;
    unite(mp[av[i]], mp[bv[i]], par);
  }

  if (mp.find(1) == mp.end()) {
    cout << 1 << endl;
    return 0;
  }

  // cout << "doge" << endl;
  ll res = 1ll;
  rep(i, n) {
    if (is_same_group(mp[av[i]], mp[1], par)) {
      res = max(av[i], res);
      res = max(bv[i], res);
    }
  }
  cout << res << endl;

  return 0;
}
#endif
