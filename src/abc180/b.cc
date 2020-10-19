#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Triple {
  ll m, c;
  long double y;
  Triple(ll mm, long double yy, ll cc) {
    m = mm;
    y = yy;
    c = cc;
  }
};

Triple solve(ll n, vector<ll> x) {
  ll m = 0, c = 0;
  long double y = 0;
  for (ll i = 0; i < n; i++) {
    ll a = abs(x[i]);
    m += a;
    y += pow(a, 2);
    c = max(a, c);
  }
  return Triple(m, sqrt(y), c);
}
/*
main() {
  ll n;
  cin >> n;
  vector<ll> x(n);
  for (ll i = 0; i < n; i++) {
    cin >> x[i];
  }
  Triple t = solve(n, x);
  cout << t.m << endl;
  cout << fixed << setprecision(10) << t.y << endl;
  cout << t.c;
}
*/