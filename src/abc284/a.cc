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
  int n;
  cin >> n;
  vector<string> sv(n);
  rep(i, n) {
    cin >> sv[i];
  }
  for(int i=n-1;i>=0;i--)
    cout << sv[i] << endl;
  return 0;
}
#endif
