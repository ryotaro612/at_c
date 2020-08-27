#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a(ll n) {
  // even
  if(n % 2 == 1) {
    return n * 2;
  }
  return n;
}
/*
int main() {
  ll n;
  cin >> n;
  cout << a(n);
}
*/
