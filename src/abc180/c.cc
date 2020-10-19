#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(ll n) {
  vector<ll> res;

  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ll c = n / i;
      res.push_back(i);
      if (i != c) {
        res.push_back(c);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}
/*
int main() {
  ll n;
  cin >> n;
  vector<ll> res = solve(n);
  for (auto r : res) {
    cout << r << endl;
  }
}
*/