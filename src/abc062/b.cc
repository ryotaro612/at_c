#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

//#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  string round = string(w + 2, '#');
  cout << round << endl;
  rep(i, h) {
    string g;
    cin >> g;
    cout << "#" << g << "#" << endl;
  }
  cout << round << endl;
  return 0;
}
//#endif
