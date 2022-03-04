#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//#ifdef ONLINE_JUDGE
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> mv(n);
  rep(i, n) { cin >> mv[i]; }
  int res = 0;
  rep(i, n) {
    res++;
    x -= mv[i];
  }
  int mi = *min_element(mv.begin(), mv.end());
  cout << res + x / mi << endl;

  return 0;
}
//#endif
