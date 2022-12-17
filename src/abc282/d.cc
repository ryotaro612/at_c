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
  else
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

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);

  vector<int> par(n, -1);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
    unite(u, v, par);
  }
  queue<int> que;
  vector<int> colors(n, -1);
  bool are_bibartites = true;
  rep(i, n) {
    if (colors[i] != -1)
      continue;
    colors[i] = 0;
    que.push(i);

    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int neighbor : g[u]) {
        if (colors[neighbor] == -1) {
          if (colors[u] == 0)
            colors[neighbor] = 1;
          else
            colors[neighbor] = 0;
          que.push(neighbor);
        } else if (colors[neighbor] == colors[u]) {
          are_bibartites = false;
        }
      }
    }
  }
  if (!are_bibartites) {
    cout << 0 << endl;
    return 0;
  }
  map<int, vector<int>> bipartites;
  rep(i, n) {
    int root = find_root(i, par);
    bipartites[root].push_back(i);
  }
  ll res = 0;
  // rep(i, n) { cout << i << " " << colors[i] << endl; }
  for (auto [_, nodes] : bipartites) {
    set<int> blacks, whites;

    for (int node : nodes) {
      if (colors[node])
        blacks.insert(node);
      else
        whites.insert(node);
    }

    ll temp = 0;
    for (int node : nodes) {
      // cout << "node: " << node << " ";
      if (blacks.find(node) == blacks.end()) {
        temp += blacks.size() - g[node].size();
        // cout << blacks.size() << endl;
      } else {
        temp += whites.size() - g[node].size();
        // cout << whites.size() << endl;
      }
      res += (ll)n - nodes.size();
    }
    res += temp;
  }
  cout << res / 2 << endl;

  return 0;
}
#endif
