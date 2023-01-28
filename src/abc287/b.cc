#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

//#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> sv(n);
  rep(i, n) cin >> sv[i];
  map<string, bool> mp;
  rep(i, m) {
    string s;
    cin >> s;
    mp[s] = true;
  }
  int res = 0;
  rep(i, n) {
    string f(sv[i].begin() + 3, sv[i].end());
    if (mp[f])
      res++;
  }
  cout << res << endl;
  return 0;
}
//#endif
