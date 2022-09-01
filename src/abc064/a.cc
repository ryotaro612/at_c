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
  string s(3, ' ');
  cin >> s[0] >> s[1] >> s[2];
  int a = stoi(s);
  if (a % 4 == 0)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;

  return 0;
}
#endif
