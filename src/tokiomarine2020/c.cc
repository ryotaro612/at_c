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

void solve(int n, int k, vector<ll> &av) {
  vector<ll> prev(n);
  rep(i, k) {
    vector<ll> temp(n);
    rep(j, n) {
      temp[max(j - av[j], 0ll)]++;
      if (j + 1 + av[j] < n)
        temp[j + 1 + av[j]]--;
    }
    for (int j = 1; j < n; j++)
      temp[j] += temp[j - 1];

    rep(j, n) {
      av[j] = temp[j];
      // cout << av[j] << " ";
    }
    bool ok = true;
    rep(j, n) {
      if (prev[j] != av[j]) {
        ok = false;
        break;
      }
    }
    if (ok)
      return;
    prev = vector<ll>(av);
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> av(n, 0);
  rep(i, n) cin >> av[i];
  solve(n, k, av);
  rep(i, n) cout << av[i] << " \n"[i == n - 1];

  return 0;
}
#endif
