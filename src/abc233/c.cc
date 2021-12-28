//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void rec(int index, ll mul, int &res, int n, ll x, vector<int> &lv,
         vector<vector<ll>> &av) {
  if (index == n) {
    if (mul == x)
      res++;
    return;
  }
  for (int i = 0; i < lv[index]; i++) {
    if (mul > x / av[index][i])
      continue;
    rec(index + 1, mul * av[index][i], res, n, x, lv, av);
  }
}

int solve(int n, ll x, vector<int> &lv, vector<vector<ll>> &av) {
  int res = 0;
  rec(0, 1ll, res, n, x, lv, av);
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll x;
  cin >> n >> x;
  vector<int> l(n);
  vector<vector<ll>> a;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
    a.push_back(vector<ll>(l[i]));
    for (int j = 0; j < l[i]; j++)
      cin >> a[i][j];
  }
  cout << solve(n, x, l, a) << endl;
  return 0;
}
#endif
