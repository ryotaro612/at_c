#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> pv(n), rev(n + 1);
  rep(i, n) cin >> pv[i];
  rep(i, n) { rev[pv[i] - 1] = i; }
  int steps = 1, temp = 1;
  // rep(i, n) cout << rev[i] << " \n"[i == n - 1];
  rep(i, n - 1) {
    if (rev[i] < rev[i + 1]) {
      temp++;
      steps = max(steps, temp);
    } else
      temp = 1;
  }
  cout << n - steps << endl;

  return 0;
}
#endif
