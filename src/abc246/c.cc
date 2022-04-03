#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <queue>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll k, x;
  cin >> n >> k >> x;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];

  priority_queue<ll> que;
  rep(i, n) { que.push(av[i]); }

  while (true) {
    ll a = que.top();
    // cout << a << " " << k << endl;
    que.pop();
    if (a == 0)
      break;

    if (k == 0) {
      que.push(a);
      break;
    }

    ll max_ticket = a / x;
    if (max_ticket <= k) {
      if (max_ticket == 0) {
        que.push(max(a - x, 0ll));
        k -= 1;
      } else {
        que.push(a - max_ticket * x);
        k -= max_ticket;
      }
    } else { // k < max_ticket;
      a -= x * k;
      k = 0;
      que.push(a);
    }
  }
  ll res = 0;
  while (!que.empty()) {
    res += que.top();
    que.pop();
  }
  cout << res << endl;

  return 0;
}
//#endif
