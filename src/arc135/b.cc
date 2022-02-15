#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <limits>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<ll> solve(int n, vector<ll> &sv) {
  if (n == 1) {
    return {0ll, 0ll, sv[0]};
  }
  vector<ll> av(n + 2, 0);
  rep(i, 3) {
    if (i + 1 < n) {
      if (sv[i + 1] - sv[i] < 0)
        av[i] = sv[i] - sv[i + 1];
      else
        av[i] = 0;
    }
  }
  rep(i, n - 1) { av[i + 3] = sv[i + 1] - sv[i] + av[i]; }
  ll offset[3] = {0, 0, 0};
  rep(i, n + 2) {
    if (av[i] < 0)
      offset[i % 3] = max(-av[i], offset[i % 3]);
  }
  rep(i, n + 2) { av[i] += offset[i % 3]; }
  if (sv[0] < av[0] + av[1] + av[2]) {
    return {};
  }
  ll gap = sv[0] - av[0] - av[1] - av[2];
  for (int i = 0; i < n + 2; i += 3) {
    av[i] += gap;
  }
  return av;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> sv(n);
  rep(i, n) cin >> sv[i];
  vector<ll> res = solve(n, sv);
  if ((int)res.size() == 0) {
    cout << "No";
    return 0;
  }
  cout << "Yes" << endl;
  rep(i, n + 2) {
    cout << res[i];
    if (i == n + 1)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
#endif
