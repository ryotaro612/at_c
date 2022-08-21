#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

int lower_bit(int i, int a) {
  int mask = (1 << (i + 1)) - 1;
  return a & mask;
}

int solve(int m, int k, vector<int> &av) {
  int res = 0;
  for (int i = 30; i >= 0; i--) {
    vector<int> cands;
    for (auto &e : av)
      cands.push_back(lower_bit(i, e));
    sort(cands.begin(), cands.end(), greater<int>());

    vector<int> temp;
    int cost = 0;
    for (auto cand : cands) {
      if (cand & (1 << i))
        temp.push_back(cand);
      else {
        if (k <= (int)temp.size())
          break;
        int current_cost = (1 << i) - cand;
        if (current_cost + cost <= m) {
          temp.push_back(cand);
          cost += current_cost;
        }
      }
    }
    if (k <= (int)temp.size()) {
      rep(j, temp.size()) temp[j] = max(temp[j], 1 << i);
      res |= 1 << i;
      av = temp;
      m -= cost;
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(m, k, av) << endl;
  return 0;
}
#endif
