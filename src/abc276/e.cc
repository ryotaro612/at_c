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

vector<pair<int, int>> find_neighbors(int i, int j, vector<string> &sv) {
  int h = sv.size();
  int w = sv[0].size();
  vector<pair<int, int>> results = {};
  vector<pair<int, int>> cands = {
      {i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}};

  for (pair<int, int> p : cands) {
    int c_i = p.first;
    int c_j = p.second;
    if (0 <= c_i && c_i < h && 0 <= c_j && c_j < w && sv[c_i][c_j] == '.')
      results.push_back({c_i, c_j});
  }
  return results;
}

bool solve(int h, int w, vector<string> &sv, int start_i, int start_j, int a_i,
           int a_j) {

  vector<int> par(h * w, -1);

  queue<pair<int, int>> que;

  que.push({a_i, a_j});

  while (que.size() > 0) {
    pair<int, int> p = que.front();
    int i = p.first;
    int j = p.second;
    que.pop();

    vector<pair<int, int>> neighbors = find_neighbors(i, j, sv);
    for (auto [n_i, n_j] : neighbors) {
      int next_node = n_i * w + n_j;
      int node = i * w + j;
      if (!is_same_group(node, next_node, par)) {
        unite(node, next_node, par);
        que.push({n_i, n_j});
      }
    }
  }
  vector<pair<int, int>> a = find_neighbors(start_i, start_j, sv);
  for (auto [b_i, b_j] : a) {
    if (b_i == a_i && b_j == a_j)
      continue;
    if (is_same_group(a_i * w + a_j, b_i * w + b_j, par)) {
      cout << "Yes" << endl;
      return true;
    }
  }
  return false;
}

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> sv(h);
  rep(i, h) cin >> sv[i];
  pair<int, int> start = {-1, -1};
  rep(i, h) {
    rep(j, w) {
      if (sv[i][j] == 'S') {
        start = {i, j};
      }
    }
  }
  assert(start.first != -1 && start.second != -1);

  vector<pair<int, int>> neighbors =
      find_neighbors(start.first, start.second, sv);
  for (pair<int, int> p : neighbors) {
    int i = p.first;
    int j = p.second;
    if (solve(h, w, sv, start.first, start.second, i, j))
      return 0;
  }
  cout << "No" << endl;
  return 0;
}
#endif
