#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> av(n), bv(m);
  rep(i, n) cin >> av[i];
  rep(i, m) cin >> bv[i];
  unordered_map<ll, int> count;
  for (ll a : av)
    count[a]++;
  rep(i, m) {
    count[bv[i]]--;
    if (count[bv[i]] < 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
#endif
