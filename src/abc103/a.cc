#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n = 3;
  vector<int> av(n);
  rep(i, n) { cin >> av[i]; }
  sort(av.begin(), av.end());
  int res = 1 << 30;
  do {
    res = min(res, abs(av[1] - av[0]) + abs(av[2] - av[1]));

  } while (next_permutation(av.begin(), av.end()));
  cout << res << endl;
  return 0;
}
#endif
