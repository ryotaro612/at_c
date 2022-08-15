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
  string n;
  cin >> n;
  string rn(n);
  reverse(rn.begin(), rn.end());
  if (n == rn)
    cout << "Yes";
  else
    cout << "No";
  cout << endl;
  return 0;
}
#endif
