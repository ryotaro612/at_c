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
  vector<int> av(10);
  rep(i, 10) cin >> av[i];

  int res = av[0];
  res = av[res];
  res = av[res];

  cout << res << endl;

  return 0;
}
#endif
