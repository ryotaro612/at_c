#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

string b(ll n) {
  ll sum = 0;
  ll nn = n;
  while(nn !=0) {
    sum += (nn % 10);
    nn /= 10;
  }
  return (n % sum == 0) ? "Yes" : "No";
}
/*
int main() {
  ll n;
  cin >> n;

  cout << b(n);
}
*/
