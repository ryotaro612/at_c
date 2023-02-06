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
bool is_same_group(int a, int b, vector<int> &par) {
  return find_root(a, par) == find_root(b, par);
}
int group_size(int a, vector<int> &par) { return -par[find_root(a, par)]; }

void unite(int a, int b, vector<int> &par) {
  int root_a = find_root(a, par), root_b = find_root(b, par);
  if (root_a == root_b)
    return;
  else if (par[root_a] < par[root_b]) {
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
  vector<int> colors(n);
  rep(i, n) cin >> colors[i];
  vector<int> par(n, -1);

  rep(i, n) {
    if (colors[(i + n - 1) % n] == colors[i]) {
      unite(i, (i + n - 1) % n, par);
    }
    if (colors[i] == colors[(i + 1) % n]) {
      unite(i, (i + 1) % n, par);
    }
  }
  int max_size = 0;
  rep(i, n) { max_size = max(max_size, group_size(i, par)); }
  if (max_size == n) {
    cout << -1 << endl;
  } else if (2 < max_size) {
    cout << (max_size - 2 + 1) / 2 + 1 << endl;
  } else {
    cout << 1 << endl;
  }

  return 0;
}
#endif
