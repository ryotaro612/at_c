#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll solve(int n, vector<ll> a, vector<ll> b) {
  ll res = 0;
  for (int k = 29; k >= 0; k--) {
    ll bekihigh = 1 << (k + 1), bekilow = (1 << k);
    for (int i = 0; i < n; i++) {
      a[i] %= bekihigh;
      b[i] %= bekihigh;
    }
    sort(b.begin(), b.end());
    ll count = 0;
    for (int i = 0; i < n; i++) {
      count += (lower_bound(b.begin(), b.end(), 2*bekilow - a[i]) - lower_bound(b.begin(), b.end(), bekilow - a[i]));
      count += (lower_bound(b.begin(), b.end(), 4*bekilow - a[i]) - lower_bound(b.begin(), b.end(), 3*bekilow - a[i]));
    }
    if (count % 2 == 1) {
      res += bekilow;
    }
  }
  return res;
}
/*
int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  cout << solve(n, a, b);
}
*/