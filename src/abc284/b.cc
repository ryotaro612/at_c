#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for(int i =0;i<(int)(n);i++)

#ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  rep(i, t) {
    int n;
    cin >> n;
    int res = 0;
    rep(j, n) {
      ll a;
      cin >> a;
      if(a % 2)
	res++;
    }
    cout << res << endl;
  }
  return 0;
}
#endif
