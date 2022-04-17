#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Query {
  int index, l, r, x;
};

vector<int> solve(int n, vector<int> &av, int q, vector<Query> &queries) {

  unordered_map<int, vector<int>> a_pos;
  rep(i, n) { a_pos[av[i]].push_back(i); }

  vector<int> res(q, 0);
  rep(i, q) {
    Query query = queries[i];
    if (a_pos[query.x].size() == 0) {
      continue;
    }
    auto left =
        lower_bound(a_pos[query.x].begin(), a_pos[query.x].end(), query.l - 1);
    auto right =
        lower_bound(a_pos[query.x].begin(), a_pos[query.x].end(), query.r);
    res[i] = distance(left, right);
  }
  // x -> Query
  // unordered_map<int, vector<Query>> x_to_queries;
  // for (Query query : queries) {
  //   x_to_queries[query.x].push_back(query);
  // }
  // for (pair<int, vector<Query>> entry : x_to_queries) {
  //   int x = entry.first;
  //   vector<int> v = a_pos[x];

  //   lower_bound(v.begin(), v.end(), );
  // }

  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  int q;
  cin >> q;
  vector<Query> queries(q);
  rep(i, q) {
    int l, r, x;
    cin >> l >> r >> x;
    queries[i] = {i, l, r, x};
  }
  vector<int> res = solve(n, av, q, queries);
  for (auto e : res)
    cout << e << endl;
  return 0;
}
#endif
