#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool is_five(ll x, ll y, ll i, ll j) {
  ll dist = (x - i) * (x - i);
  if (5ll < dist)
    return false;
  dist += (y - j) * (y - j);
  return dist == 5ll;
}

string solve(ll x1, ll y1, ll x2, ll y2) {

  for (ll i = x1 - 5ll; i <= x1 + 5ll; i++) {
    for (ll j = y1 - 5ll; j <= y1 + 5ll; j++) {
      if (is_five(x1, y1, i, j) && is_five(x2, y2, i, j))
        return "Yes";
    }
  }
  return "No";
}

#ifdef ONLINE_JUDGE
int main() {
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << solve(x1, y1, x2, y2) << endl;
  return 0;
}
#endif
