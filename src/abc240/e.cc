#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void rec_l(int node, vector<vector<int>> &g, vector<int> &height, int &index,
           vector<pair<int, int>> &res) {
  if (g[node].size() == 1 && height[g[node][0]] < height[node]) {
    res[node].first = index;
    res[node].second = index;
    index++;
    return;
  }
  int mini = 1000000;
  int maxi = 0;
  for (int neigh : g[node]) {
    if (height[node] < height[neigh]) {
      rec_l(neigh, g, height, index, res);
      mini = min(mini, res[neigh].first);
      maxi = max(maxi, res[neigh].second);
    }
  }
  res[node].first = mini;
  res[node].second = maxi;
}

vector<pair<int, int>> solve(int n, vector<int> &uv, vector<int> &vv) {
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    uv[i]--;
    vv[i]--;
    g[uv[i]].push_back(vv[i]);
    g[vv[i]].push_back(uv[i]);
  }

  vector<int> height(n, -1);
  queue<int> que;
  que.push(0);
  height[0] = 0;

  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (int neigh : g[node]) {
      if (height[neigh] < 0) {
        height[neigh] = height[node] + 1;
        que.push(neigh);
      }
    }
  }
  vector<pair<int, int>> res(n, {-1, -1});
  int index = 1;
  rec_l(0, g, height, index, res);
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> uv(n - 1), vv(n - 1);
  rep(i, n) { cin >> uv[i] >> vv[i]; }
  vector<pair<int, int>> res = solve(n, uv, vv);
  for (auto e : res)
    cout << e.first << " " << e.second << endl;
  return 0;
}
#endif
