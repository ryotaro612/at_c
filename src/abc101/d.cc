#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


pair<ll, ll> digit_sum(ll d) {
  ll dd = d;
  ll res = 0;
  ll count = 0;
  while(dd > 0) {
    res += dd % 10;
    dd /= 10;
    count++;
  }
  return make_pair(count, res);
}


ll sunuke(ll n) {
  pair<ll, ll> count_sum = digit_sum(n);
  double a =  (double) n / (double) count_sum.second;
  ll b = n;
  for(int i=1;i<=count_sum.first;i++) {
    ll cand = n - ((ll) (n % (ll) pow(10, i))) + pow(10, i) - 1;
    pair<ll, ll> p = digit_sum(cand);
    if(a > ((double) cand / (double) p.second)) {
      a = (double) cand / (double) p.second;
      b = cand;
    }
  }
  return b;
}

vector<ll> d(ll k) {
  vector<ll> res;
  res.push_back(1);
  ll i = 2;
  while((ll) res.size()<k) {
    i = sunuke(i);
    res.push_back(i);
    i++;
  }
  return res;
}
/*
int main() {
  ll k;
  cin >> k;
  vector<ll> res = d(k);
  for(auto i: res) {
    cout << i << endl;
  }
}
*/
