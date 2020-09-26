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
  ll lb = -1, ub = n;
  vector<ll> b = vector<ll>(n, 0);

  for(ll i=0;i<n;i++) {
    b[i] = a[i];
  }
  sort(b.begin(), b.end(), greater<ll>());
  ll offset = n + 1;
  while(ub - lb > 1) {
    vector<ll> s = vector<ll>(n, 0);
    ll mid = (lb + ub) / 2;

    Bit bit = Bit(n*2 + 10);
    s[0] = b[mid] <= a[0] ? 1 : -1;
    bit.add(offset + s[0], 1);
    ll num = (s[0] == 1 ? 1 : 0);

    for(ll i=1;i<n;i++) {
      s[i] = s[i-1] + (b[mid] <= a[i] ? 1 : -1);
      num += bit.sum(offset + s[i]);

      bit.add(offset + s[i], 1);
      if(s[i]>=0)
	num++;
    }
    if(num >= (n+1)*n/4) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  return b[ub];
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
