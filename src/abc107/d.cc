#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

class Bit {
  public:
    int n;
    vector<ll> bit;

    Bit(int nn) {
      n = nn;
      vector<ll> b(n+1, 0);
      bit = b;
    }

    ll sum(int i) {
      int s= 0;
      while(i > 0) {
	s += bit[i];
	i -= i & -i;
      }
      return s;
    }

    void add(int i, ll x) {
      while(i <= n) {
	bit[i] += x;
	i += i & -i;
      }
    }
};

ll d(int n, vector<ll> a) {
  vector<ll> b(n);
  copy(a.begin(), a.end(), b.begin());
  sort(b.begin(), b.end());

  int low = 0;
  int high = 1<<30;
  int offset = n+1;
  while(high - low > 1) {
    int mid = (low + high) / 2;
    int num = 0;
    cout << "low " << low << " mid " << mid << " high: " << high << endl;
    vector<int> acc(n);
    Bit bit = Bit(2*n+10);
    bit.add(offset, 1);
    acc[0] = (mid >= a[0] ? 1 : -1);
    for(int i=1;i<n;i++) {
      acc[i] += acc[i-1] + (mid >= a[i] ? 1 : -1);
    }
    for(int j=0;j<n;j++) {
      num += bit.sum(offset + acc[j]);
      bit.add(offset + acc[j], 1);
    }
    cout << " num " << num  << " cond: " << ((n*(n-1)/2) + n)/2 << endl;
    if(num > ((n*(n-1)/2) + n)/2) {
      cout << "see left" << endl;
      high = mid;
    } else {
      cout << "see right" << endl;
      low = mid;
    }
  }
  return high;
}
/*
int main() {
  int n;
  cin >> n;
  vector<ll> a(n) ;
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << d(n, a);
}
*/
