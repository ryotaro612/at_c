#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int find_root(int a, vector<int> &par) {
  
  if(par[a] < 0)
    return a;
  return par[a] = find_root(par[a], par);
}
bool is_same_group(int a, int b, vector<int> &par) {
  return find_root(a, par) == find_root(b, par);
}

void unite(int a, int b, vector<int> &par) {
  if(is_same_group(a, b, par))
    return;

  int root_a = find_root(a, par);
  int root_b = find_root(b, par);
  if(par[root_a] < par[root_b]) {
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
  vector<vector<int>> g(n);
  vector<int> par(n, -1);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    unite(--u, --v, par);
  }
  set<int> res;
  rep(i,n) {
    int a = find_root(i, par);
    res.insert(a);
  }
  cout << res.size() << endl;
  return 0;
}
#endif
