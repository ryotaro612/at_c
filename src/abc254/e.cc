#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <unordered_map>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

int sub(int x, int k, vector<vector<int>> &g, unordered_set<int> &s) {

  if (k == 0) {
    if (s.find(x) == s.end()) {
      s.insert(x);
      return x + 1;
    } else {
      return 0;
    }
  }
  int res = 0;
  if (s.find(x) == s.end()) {
    res += x + 1;
    s.insert(x);
  }
  for (int neighbor : g[x]) {
    if (s.find(neighbor) == s.end()) {
      res += sub(neighbor, k - 1, g, s);
    }
  }
  // cout << x << " " << k << " " << res << endl;
  return res;
}

vector<int> solve(ll n, ll m, vector<int> &av, vector<int> &bv, int q,
                  vector<int> &xv, vector<int> &kv) {
  vector<vector<int>> g(n);
  rep(i, m) {
    g[--av[i]].push_back(--bv[i]);
    g[bv[i]].push_back(av[i]);
  }
  vector<int> res;

  rep(i, q) {
    // cout << "q: " << i << endl;
    unordered_map<int, int> d;
    // res.push_back(sub(--xv[i], kv[i], g, s));
    queue<pair<int, int>> que;
    que.push({--xv[i], 0});
    d[xv[i]] = 0;
    while (!que.empty()) {
      pair<int, int> p = que.front();
      que.pop();
      if (d.find(p.first) != d.end()) {
        if (d[p.first] < p.second)
          continue;
      }
      if (kv[i] <= p.second)
        continue;
      for (int neighbor : g[p.first]) {
        if (d.find(neighbor) == d.end() || d[p.first] + 1 < d[neighbor]) {
          d[neighbor] = d[p.first] + 1;
          que.push({neighbor, d[neighbor]});
        }
      }
    }
    int temp = 0;
    for (auto [a, b] : d) {
      if (b <= kv[i])
        temp += a + 1;
    }
    res.push_back(temp);
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, m;
  cin >> n >> m;
  vector<int> av(m), bv(m);
  rep(i, m) cin >> av[i] >> bv[i];
  int q;
  cin >> q;
  vector<int> xv(q), kv(q);
  rep(i, q) cin >> xv[i] >> kv[i];
  rep(i, q) { cin >> xv[i] >> kv[i]; }
  vector<int> res = solve(n, m, av, bv, q, xv, kv);
  for (auto e : res)
    cout << e << endl;
  return 0;
}
#endif
