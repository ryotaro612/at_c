#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

class Bit {
  public:
    ll n;
    vector<ll> bit;

    Bit(ll nn) {
      n = nn;
      vector<ll> b(n+1, 0);
      bit = b;
    }

    ll sum(ll i) {
      ll s= 0;
      while(i > 0) {
	s += bit[i];
	i -= i & -i;
      }
      return s;
    }

    void add(ll i, ll x) {
      while(i <= n) {
	bit[i] += x;
	i += i & -i;
      }
    }
};

ll d(ll n, vector<ll> a) {

  return b[low];
}
/*
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n) ;
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << d(n, a);
}
*/
