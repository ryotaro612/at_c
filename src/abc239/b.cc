#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  ll x;
  cin >> x;
  if (x >= 0ll || x % 10ll == 0ll) {
    cout << x / 10ll << endl;
  } else {
    cout << x / 10ll - 1ll << endl;
  }

  return 0;
}
#endif
