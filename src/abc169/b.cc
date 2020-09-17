#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<ll> a) {
  ll ans = 1;
  for(int i=0;i<n;i++) {
    if(a[i] == 0) {
      return 0;
    }
  }
  for(auto aa: a) {
    if(aa <= 1000000000000000000/ans) {
      ans *= aa;
    } else {
      return -1;
    }
  }
  if(ans > 1000000000000000000 || ans <=0) {
    return -1;
  }
  return ans;
}
/*
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve(n, a);
}
*/
