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
  if (par[a] < 0)
    return a;
  return par[a] = find_root(par[a], par);
}
int is_same_group(int a, int b, vector<int> &par) {
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

  int n, m;
  cin >> n >> m;
  if (n != m + 1) {
    cout << "No" << endl;
    return 0;
  }
  vector<int> par(n, -1);
  vector<int> conn(n, 0);

  rep(i, m) {
    int u, v;
    cin >> u >> v;
    conn[--u]++;
    conn[--v]++;
    unite(u, v, par);
  }
  set<int> groups;
  rep(i, n) { groups.insert(find_root(i, par)); }
  if (groups.size() != 1) {
    cout << "No" << endl;
    return 0;
  }

  int one = 0, two = 0;
  rep(i, n) {
    if (conn[i] == 1)
      one++;
    else if (conn[i] == 2)
      two++;
  }

  // cout << one << " " << two << endl;
  if (one == 2 && two == n - 2) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
  return 0;
}
#endif
