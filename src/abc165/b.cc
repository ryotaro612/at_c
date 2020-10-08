#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll solve(ll x) {
    ll res = 0;
    ll c = 100;
    while(c<x) {
      c += (ll)(c /100);
      res++;
    }

    return res;
}
/*
int main() {
  ll x;
  cin >> x;
  cout << solve(x);
}
*/