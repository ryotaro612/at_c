#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

int find_root(int a, vector<int> &par) {
  // cout << a << par[a] << endl;
  if (par[a] < 0)
    return a;
  return par[a] = find_root(par[a], par);
}

bool is_same_group(int a, int b, vector<int> &par) {
  return find_root(a, par) == find_root(b, par);
}
void unite(int a, int b, vector<int> &par) {
  int root_a = find_root(a, par);
  int root_b = find_root(b, par);
  if (is_same_group(a, b, par))
    return;

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
  int n, m;
  cin >> n >> m;
  vector<int> av(m), bv(m);
  vector<int> par(n, -1);
  rep(i, m) {
    cin >> av[i] >> bv[i];
    av[i]--;
    bv[i]--;
    // cout << av[i] << bv[i] << endl;
    unite(av[i], bv[i], par);
  }
  // cout << "doge2" << endl;
  set<int> roots;
  rep(i, n) roots.insert(find_root(i, par));
  map<int, int> edges;
  rep(i, m) { edges[find_root(av[i], par)]++; }
  int res = 0;
  // cout << "doge" << endl;
  for (auto root : roots) {
    res += max(0, edges[root] - (-par[root] - 1));
  }
  cout << res << endl;
  return 0;
}
#endif
