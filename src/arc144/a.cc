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
  int n;
  cin >> n;
  int m = n * 2;
  string s(n / 4, '4');
  if (n % 4 > 0)
    s.push_back(n % 4 + '0');
  reverse(s.begin(), s.end());
  cout << m << endl;
  cout << s << endl;
  return 0;
}
#endif
