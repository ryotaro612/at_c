#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<ll> solve(int q, vector<vector<ll>> &queries) {
  vector<ll> res;
  multiset<ll> st;
  for (auto query : queries) {
    if (query[0] == 1) {
      st.insert(query[1]);
    } else if (query[0] == 2) {
      ll c = query[2];
      ll x = query[1];
      rep(i, c) {
        auto iter = st.find(x);
        if (iter == st.end())
          break;
        else
          st.erase(iter);
      }
    } else {

      res.push_back(*prev(st.end()) - *st.begin());
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int q;
  cin >> q;
  vector<vector<ll>> queries(q, vector<ll>(3));
  rep(i, q) {
    cin >> queries[i][0];
    if (queries[i][0] == 1) {
      cin >> queries[i][1];
    } else if (queries[i][0] == 2) {
      cin >> queries[i][1] >> queries[i][2];
    }
  }
  vector<ll> res = solve(q, queries);
  for (auto e : res)
    cout << e << endl;
  return 0;
}
#endif
