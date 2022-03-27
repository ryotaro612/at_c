#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  unordered_set<int> as(av.begin(), av.end());
  for (int i = 0;; i++) {
    if (as.find(i) == as.end()) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
//#endif
