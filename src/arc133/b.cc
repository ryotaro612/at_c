#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int solve(int n, vector<int> &p, vector<int> &q) {
  vector<int> value_index(n + 1);
  rep(i, n) { value_index[q[i]] = i; }
  vector<pair<int, int>> index_pairs;
  rep(i, n) {
    int v = p[i];
    while (v <= n) {
      index_pairs.push_back({i, value_index[v]});
      v += p[i];
    }
  }
  sort(index_pairs.begin(), index_pairs.end(),
       [&](const pair<int, int> &a, const pair<int, int> &b) {
         if (a.first != b.first)
           return a.first < b.first;
         else
           return -a.second < -b.second;
       });
  /*
  rep(i, index_pairs.size()) {
    cout << index_pairs[i].first << " , " << index_pairs[i].second << endl;
  }
  */
  int inf =  1<< 30;
  vector<int> order(index_pairs.size(), inf);
  rep(i, order.size()) {
    vector<int>::iterator iter = lower_bound(
        order.begin(), order.end(), index_pairs[i].second);
    *iter = index_pairs[i].second;
  }
  return lower_bound(order.begin(), order.end(), inf) - order.begin();
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];
  cout << solve(n, p, q) << endl;
}
#endif
