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
  vector<ll> b(n);
  copy(a.begin(), a.end(), b.begin());
  sort(b.begin(), b.end());

  ll low = -1;
  //ll high = 1<<30;
  ll high = n;
  ll offset = n+1;
  ll total_pairs = (n*(n-1)/2) + n;
  cout << "total pair " << total_pairs << endl;
  while(high - low > 1) {
    ll mid = (low + high) / 2;
    cout << "low " << low << " mid " << mid << " high: " << high << " -> " << b[mid]<< endl;
    vector<ll> acc(n);
    Bit bit = Bit(3*n+10);
    acc[0] = (b[mid] > a[0] ? -1 : 1);
    ll num = 0;
    if(b[mid] <= a[0]) {
      num++;
    }
    for(ll i=1;i<n;i++) {
      acc[i] += acc[i-1] + (b[mid] > a[i] ? -1 : 1);
      if(b[mid] <= a[i]) {
	num++;
      }
    }
    cout << "num : " << num << endl;
    for(ll j=0;j<n;j++) {
      //cout << j << " -> num " << num << " " << bit.sum(offset + acc[j]) << endl;
      num += bit.sum(offset + acc[j]);
      bit.add(offset + acc[j], 1);
    }
    cout <<total_pairs - num <<  " : "  << num << endl;
    if( total_pairs - num > num) {
      cout << "see left" << endl;
      high = mid;
    } else {
      cout << "see right" << endl;
      low = mid;
    }
  }
  cout << b[high] << endl;
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
