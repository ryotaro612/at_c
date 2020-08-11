#include <iostream>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;


set<ll> prime_factor(ll n) {
  set<ll> ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret.insert(i);
      n /= i;
    }
  }
  if(n != 1) ret.insert(n);
  return ret;
}

ll disjoint_set_of_common_divisors(ll a, ll b) {
  set<ll> aa = prime_factor(a);
  set<ll> bb = prime_factor(b);
  set<ll> merged;
  set_intersection(aa.begin(), aa.end(), bb.begin(), bb.end(), inserter(merged, merged.end()));
  return merged.size() + 1;
}
/*
int main() {
  ll a, b;
  cin >> a >> b;
  cout << disjoint_set_of_common_divisors(a, b);
}
*/
