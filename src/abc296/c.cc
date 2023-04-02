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

#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> av(n);
  rep(i, n) { cin >> av[i]; }
  sort(av.begin(), av.end());

  rep(i, n) {
    int lb = i - 1, ub = n;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (av[mid] - av[i] >= x) {
        ub = mid;
      } else
        lb = mid;
    }
    if (av[ub] - av[i] == x) {
      cout << "Yes\n";
      return 0;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    int ub = n - 1, lb = -1;
    while (ub - lb > 1) {
      int mid = (ub + lb) / 2;
      if (av[mid] - av[i] >= x)
        ub = mid;
      else
        lb = mid;
    }
    if (av[ub] - av[i] == x) {
      cout << "Yes\n";
      return 0;
    }
  }

  cout << "No\n";

  return 0;
}
#endif
