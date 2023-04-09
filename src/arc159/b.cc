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

vector<ll> calc_divisors(ll a) {
  vector<ll> res;
  for (ll i = 1ll; i * i <= a; i++) {
    if (a % i == 0) {
      res.push_back(i);
      if (a / i != i)
        res.push_back(a / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}
ll my_gcd(ll a, ll b) {
  if (a < b)
    swap(a, b);
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

#ifdef ONLINE_JUDGE
int main() {
  ll a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 1 << endl;
    return 0;
  } else if (b < a)
    swap(a, b);
  // a < b
  vector<ll> divisors = calc_divisors(b - a);
  vector<ll> temp;
  ll g = my_gcd(b, a);
  for (auto divisor : divisors) {
    if (divisor > g)
      temp.push_back(divisor);
  }
  divisors = temp;

  ll res = 0ll;

  while (a) {
    ll next_a = -1;
    ll next_g;
    for (auto d : divisors) {
      ll ub = a / d + 1ll;
      ll lb = 0ll;
      while (ub - lb > 1) {
        ll mid = (ub + lb) / 2ll;
        if ((a - mid * d) % g == 0)
          lb = mid;
        else
          ub = mid;
      }
      if ((a - lb * d) % g == 0) {
        if (next_a < lb * d) {
          next_a = lb * d;
          next_g = d;
        }
      }
    }
    if (next_a == -1) {
      res += a / g;
      break;
    } else {
      res += (a - next_a) / g;
      a = next_a;
      g = next_g;
      vector<ll> temp;
      for (auto d : divisors) {
        if (d > g)
          temp.push_back(d);
      }
      divisors = temp;
    }
  }

  cout << res << endl;

  return 0;
}
#endif
