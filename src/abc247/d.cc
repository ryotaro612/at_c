#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct Query {
  int kind;
  ll x, c;
};

vector<ll> solve(vector<Query> &queries) {
  deque<pair<ll, ll>> que;
  vector<ll> res;
  for (Query query : queries) {
    // cout << "doge" << endl;
    if (query.kind == 1) {
      que.push_back({query.x, query.c});
    } else {
      ll remain = query.c;
      ll sum = 0ll;
      while (0 < remain) {
        ll x = que.front().first;
        ll c = que.front().second;
        que.pop_front();
        if (c <= remain) {
          sum += x * c;
          remain -= c;
        } else { // remain < c
          sum += x * remain;
          que.push_front({x, c - remain});
          remain = 0;
        }
      }
      res.push_back(sum);
    }
  }
  return res;
}

//#ifdef ONLINE_JUDGE
int main() {
  int q;
  cin >> q;
  vector<Query> queries(q);
  rep(i, q) {
    int kind;
    ll x = 0, c = 0;
    cin >> kind;
    if (kind == 1) {
      cin >> x >> c;
    } else {
      cin >> c;
    }
    queries[i] = {kind, x, c};
  }
  vector<ll> res = solve(queries);
  rep(i, res.size()) { cout << res[i] << endl; }
  return 0;
}
//#endif
