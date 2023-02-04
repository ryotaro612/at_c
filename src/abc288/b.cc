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
  int n, k;
  cin >> n >> k;
  vector<string> sv(k);
  rep(i, k) cin >> sv[i];
  sort(sv.begin(), sv.end());
  rep(i, k) cout << sv[i] << endl;
  return 0;
}
//#endif
