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
  unordered_set<int> s;
  rep(i, n) {
    int d;
    cin >> d;
    s.insert(d);
  }
  cout << s.size() << endl;
  return 0;
}
#endif
