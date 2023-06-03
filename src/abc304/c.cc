#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  ll n, d;
  cin >> n >> d;
  vector<ll> xv(n), yv(n);
  rep(i, n) cin >> xv[i] >> yv[i];
  vector<bool> infected(n, false);
  infected[0] = true;
  queue<int> que;
  que.push(0);
  while (que.size()) {
    int node = que.front();
    que.pop();
    rep(i, n) {
      if (infected[i])
        continue;
      if (abs(xv[i] - xv[node]) * abs(xv[i] - xv[node]) +
              (yv[i] - yv[node]) * (yv[i] - yv[node]) <=
          d * d) {
        infected[i] = true;
        que.push(i);
      }
    }
  }
  rep(i, n) {
    if (infected[i])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
#endif
