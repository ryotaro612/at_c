#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Query {
  int type;
  ll x;
  int k;
};
vector<ll> solve(int q, vector<Query> &queries) {

  vector<ll> res;
  multiset<ll> a;
  for (Query query : queries) {
    if (query.type == 1) {
      a.insert(query.x);
    } else if (query.type == 2) {
      auto iter = a.upper_bound(query.x);
      bool ok = true;
      rep(i, query.k) {
        if (iter == a.begin())
          ok = false;
        else
          iter--;
      }
      if (ok)
        res.push_back(*iter);
      else
        res.push_back(-1);
    } else {
      auto iter = a.lower_bound(query.x);
      rep(i, query.k - 1) {
        if (iter == a.end())
          break;
        else
          iter++;
      }
      if (iter == a.end())
        res.push_back(-1);
      else
        res.push_back(*iter);
    }
  }
  return res;
}
#ifdef ONLINE_JUDGE
int main() {
  int q;
  cin >> q;
  vector<Query> queries(q);
  rep(i, q) {
    int type;
    cin >> type;
    ll x;
    cin >> x;
    if (type == 1) {
      queries[i] = {type, x, -1};
    } else {
      int k;
      cin >> k;
      queries[i] = {type, x, k};
    }
  }
  vector<ll> res = solve(q, queries);
  for (auto e : res)
    cout << e << endl;
  return 0;
}
#endif
