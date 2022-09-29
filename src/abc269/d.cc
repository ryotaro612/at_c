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

bool is_same_group(int a, int b, vector<int> &par) {
  return find_root(a, par) == find_root(b, par);
}

void unite(int a, int b, vector<int> &par) {
  if (is_same_group(a, b, par))
    return;
  int root_a = find_root(a, par);
  int root_b = find_root(b, par);

  if (par[root_a] < par[root_b]) {
    par[root_a] += par[root_b];
    par[root_b] = root_a;
  } else {
    par[root_b] += par[root_a];
    par[root_a] = root_b;
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> xv(n), yv(n);
  map<pair<int, int>, int> mp;
  rep(i, n) {
    cin >> xv[i] >> yv[i];
    mp[{xv[i], yv[i]}] = i;
  }
  vector<int> par(n, -1);

  rep(i, n) {
    vector<pair<int, int>> patterns = {
        {xv[i] - 1, yv[i] - 1}, {xv[i] - 1, yv[i]}, {xv[i], yv[i] - 1},
        {xv[i], yv[i] + 1},     {xv[i] + 1, yv[i]}, {xv[i] + 1, yv[i] + 1}};

    for (auto pattern : patterns) {
      if (mp.find(pattern) != mp.end()) {
        unite(i, mp[pattern], par);
      }
    }
  }
  set<int> res;
  rep(i, n) { res.insert(find_root(i, par)); }
  cout << res.size() << endl;
  return 0;
}
#endif
