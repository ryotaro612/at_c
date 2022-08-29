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
bool same_group(int a, int b, vector<int> &par) {
  return find_root(a, par) == find_root(b, par);
}

void unite(int a, int b, vector<int> &par) {
  if (same_group(a, b, par))
    return;
  int root_a = find_root(a, par), root_b = find_root(b, par);

  if (root_a < root_b) {
    par[root_a] += par[root_b];
    par[root_b] = root_a;
  } else {
    par[root_b] += par[root_a];
    par[root_a] = root_b;
  }
}

bool find_inters(vector<vector<int>> &g, int node, int child, set<int> &found) {
  found.insert(node);
  if (node == child) {
    return true;
  }
  bool ok = false;
  for (int neighbor : g[node]) {
    if (found.find(neighbor) == found.end() &&
        find_inters(g, neighbor, child, found))
      ok = true;
  }
  if (ok)
    return true;
  else {
    found.erase(node);
    return false;
  }
}

void find_nearest_inters(vector<vector<int>> &g, int node,
                         vector<int> &nearest_inter, set<int> &inters) {

  for (int neighbor : g[node]) {
    if (nearest_inter[neighbor] == -1) {
      if (inters.find(neighbor) == inters.end()) {
        nearest_inter[neighbor] = nearest_inter[node];
      } else {
        nearest_inter[neighbor] = neighbor;
      }
      find_nearest_inters(g, neighbor, nearest_inter, inters);
    }
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> uv(n), vv(n);
  rep(i, n) {
    cin >> uv[i] >> vv[i];
    uv[i]--;
    vv[i]--;
  }
  int q;
  cin >> q;
  vector<int> xv(q), yv(q);
  rep(i, q) {
    cin >> xv[i] >> yv[i];
    xv[i]--;
    yv[i]--;
  }
  vector<int> par(n, -1);
  int root, child;
  rep(i, n) {
    if (same_group(uv[i], vv[i], par)) {
      root = uv[i], child = vv[i];
    } else {
      unite(uv[i], vv[i], par);
    }
  }
  vector<vector<int>> g(n);
  rep(i, n) {
    g[uv[i]].push_back(vv[i]);
    g[vv[i]].push_back(uv[i]);
  }
  set<int> inters;
  find_inters(g, root, child, inters);
  // cout << root << " " << child << endl;
  // for (auto e : inters)
  //   cout << e << " ";
  // cout << endl;
  vector<int> nearest_inter(n, -1);
  nearest_inter[root] = root;
  find_nearest_inters(g, root, nearest_inter, inters);
  // rep(i, n) { cout << i << " - > " << nearest_inter[i] << endl; }

  rep(i, q) {
    if (nearest_inter[xv[i]] == nearest_inter[yv[i]]) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << endl;
  }
  return 0;
}
#endif
