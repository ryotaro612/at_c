#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  string s, t;
  cin >> s >> t;
  unsigned long a = s.find(t);
  if (a == string::npos) {
    cout << "No";
  } else {
    cout << "Yes";
  }
  cout << endl;
  return 0;
}
#endif
