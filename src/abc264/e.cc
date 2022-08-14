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
ll group_size(int i, vector<int> &par) { return -par[find_root(i, par)]; }

vector<ll> solve(int n, int m, int e, vector<int> &uv, vector<int> &vv, int q,
                 vector<int> &xv) {
  unordered_set<int> densens;
  rep(i, e) {
    uv[i]--;
    vv[i]--;
    densens.insert(i);
  }
  rep(i, q) { densens.erase(--xv[i]); }
  vector<int> par(n + m, -1);

  for (int i : densens) {
    unite(uv[i], vv[i], par);
  }
  unordered_set<int> light_groups;
  for (int i = n; i < n + m; i++) {
    light_groups.insert(find_root(i, par));
  }
  ll current = 0;
  rep(i, n) {
    int city_group = find_root(i, par);
    if (light_groups.find(city_group) != light_groups.end()) {
      current++;
    }
  }

  vector<ll> res;
  for (int i = q - 1; i >= 0; i--) {
    res.push_back(current);
    int u = uv[xv[i]], v = vv[xv[i]];
    int root_u = find_root(u, par);
    int root_v = find_root(v, par);

    if (light_groups.find(root_u) == light_groups.end()) {
      if (light_groups.find(root_v) == light_groups.end()) {
        unite(u, v, par);
      } else {
        current += group_size(u, par);
        unite(u, v, par);
        light_groups.insert(find_root(u, par));
      }
    } else {
      if (light_groups.find(root_v) == light_groups.end()) {
        current += group_size(v, par);
        unite(u, v, par);
        light_groups.insert(find_root(u, par));
      } else {
        unite(u, v, par);
      }
    }
  }
  reverse(res.begin(), res.end());
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m, e;
  cin >> n >> m >> e;
  vector<int> uv(e), vv(e);
  rep(i, e) { cin >> uv[i] >> vv[i]; }
  int q;
  cin >> q;
  vector<int> xv(q);
  rep(i, q) cin >> xv[i];
  vector<ll> res = solve(n, m, e, uv, vv, q, xv);
  for (auto e : res)
    cout << e << endl;
  return 0;
}
#endif
