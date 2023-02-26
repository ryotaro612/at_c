#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

//#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> sv(n, vector<bool>(m));
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, m) sv[i][j] = (s[j] == '1');
  }
  const ll inf = 10000000000000ll;
  vector<ll> after(n, inf);
  queue<int> que;
  que.push(n - 1);
  after[n - 1] = 0;
  while (que.size()) {
    int node = que.front();
    que.pop();
    rep(i, m) {
      int dest = node - i - 1;
      if (dest >= 0 && sv[dest][i] && after[node] + 1ll < after[dest]) {
        que.push(dest);
        after[dest] = after[node] + 1ll;
      }
    }
  }
  // rep(i, n) cout << after[i] << endl;
  vector<ll> d(n, inf);
  d[0] = 0;
  que.push(0);
  while (que.size()) {
    int node = que.front();
    que.pop();
    rep(i, m) {
      int dest = node + i + 1;
      if (sv[node][i] && dest < n && d[node] + 1ll < d[dest]) {
        d[dest] = d[node] + 1ll;
        que.push(node + i + 1);
      }
    }
  }
  // rep(i, n) cout << d[i] << endl;
  for (int k = 1; k < n - 1; k++) {
    ll res = inf;
    for (int i = max(0, k - (m - 1)); i < k; i++) {
      rep(j, m) {
        if (sv[i][j] && k < i + j + 1) {
          res = min(res, d[i] + 1ll + after[i + j + 1]);
        }
      }
    }
    if (res < inf)
      cout << res;
    else
      cout << -1;
    cout << " \n"[k == n - 2];
  }

  return 0;
}
//#endif
