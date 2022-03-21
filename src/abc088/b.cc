#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];

  sort(av.begin(), av.end(), greater<int>());
  int alice = 0, bob = 0;
  rep(i, n) {
    if (i % 2 == 0) {
      alice += av[i];
    } else
      bob += av[i];
  }
  cout << alice - bob << endl;
  return 0;
}
#endif
