#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll solve(ll n, ll k, vector<ll> &av) {
  vector<bool> done(n, false);
  ll x = 0ll;
  int loop_start;
  int loop_count = 0;
  while (true) {
    int index = x % n;
    if (done[index]) {
      loop_start = index;
      break;
    }
    loop_count++;
    done[index] = true;
    x += av[index];
  }
  ll y = 0ll;
  while (true) {
    int index = y % n;
    if (index != loop_start) {
      loop_count--;
      y += av[index];
    } else
      break;
  }
  ll loop_x = x - y;
  x = 0ll;
  // cout << "loop x " << loop_x << endl;
  // cout << " loop_ start " << loop_start << endl;
  // cout << "loop_count " << loop_count << endl;
  while (0 < k) {
    int index = x % n;
    if (index == loop_start)
      break;
    x += av[index];
    k--;
  }
  if (k == 0)
    return x;
  x += k / loop_count * loop_x;
  k %= loop_count;
  while (0 < k) {
    int index = x % n;
    x += av[index];
    k--;
  }
  return x;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, k, av) << endl;
  return 0;
}
#endif
