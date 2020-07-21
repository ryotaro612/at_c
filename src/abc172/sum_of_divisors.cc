#include<iostream>
typedef long long ll;

using namespace std;

ll sum_of_divisors(ll n) {
  ll ans = 0;

  for(ll j = 1; j<=n;j++) {

    ll y = (ll) n / j;
    ans += (((y+1)*y)*j)/2;

  }
  return ans;

}
/*
int main() {
  long long n;
  cin >> n;
  cout << sum_of_divisors(n);
}
*/
