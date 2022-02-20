//#ifndef ONLINE_JUDGE
//#define _GLIBCXX_DEBUG
//#endif
#include <bits/stdc++.h>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

multiset<ll> get_subtree(int node, vector<vector<int>> &g, vector<int> &order,
                         vector<multiset<ll>> &sub_trees, vector<ll> &xv) {
  if (!sub_trees[node].empty()) {
    return sub_trees[node];
  }
  multiset<ll> res = {xv[node]};
  for (int neigh : g[node]) {
    if (order[node] < order[neigh]) {
      multiset<ll> su = get_subtree(neigh, g, order, sub_trees, xv);
      for (auto e : su)
        res.insert(e);
    }
  }

  if (res.size() > 20) {
    res = multiset<ll>(prev(res.end(), 20), res.end());
  }
  return sub_trees[node] = res;
}

struct Query {
  int index, v, k;
};

vector<ll> solve(int n, int q, vector<ll> &xv, vector<int> &av, vector<int> &bv,
                 vector<int> &vv, vector<int> &kv) {
  rep(i, n) xv[i];
  rep(i, n - 1) {
    av[i]--;
    bv[i]--;
  }
  rep(i, q) {
    vv[i]--;
    kv[i]--;
  }
  //子から親にもつながっている
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    g[av[i]].push_back(bv[i]);
    g[bv[i]].push_back(av[i]);
  }
  vector<int> order(n, -1);
  int index = 0;
  queue<int> que;
  que.push(0);
  order[0] = index++;

  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (auto neigh : g[node]) {
      if (order[neigh] == -1) {
        order[neigh] = index++;
        que.push(neigh);
      }
    }
  }
  vector<Query> queries(q);
  rep(i, q) { queries[i] = {i, vv[i], kv[i]}; }
  sort(queries.begin(), queries.end(),
       [&](const Query &query1, const Query &query2) {
         return order[query1.v] < order[query2.v];
       });
  vector<ll> res(q);
  vector<multiset<ll>> sub_trees(n);
  for (int i = q - 1; i >= 0; i--) {
    Query query = queries[i];
    multiset<ll> sub_t = get_subtree(query.v, g, order, sub_trees, xv);
    auto iter = sub_t.end();
    iter--;
    rep(j, query.k) { iter--; }
    res[query.index] = *iter;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> xv(n);
  rep(i, n) cin >> xv[i];
  vector<int> av(n - 1), bv(n - 1);
  rep(i, n - 1) cin >> av[i] >> bv[i];
  vector<int> vv(q), kv(q);
  rep(i, q) cin >> vv[i] >> kv[i];
  vector<ll> res = solve(n, q, xv, av, bv, vv, kv);
  for (auto e : res)
    cout << e << endl;
  return 0;
}
#endif
