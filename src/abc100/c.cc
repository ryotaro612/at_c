#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int two(ll ai) {
  int count = 0;
  while(true) {
    if(ai % 2 == 0) {
      count++; 
      ai /= 2;
    } else {
      return count;
    }
  }
}

int c(int n, vector<ll> a) {
  int count = 0;
  for(auto aa: a) {
    count += two(aa);
  }
  return count;
}
/*
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << c(n, a);
}
*/
