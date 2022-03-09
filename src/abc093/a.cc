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
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  if (s == "abc")
    cout << "Yes";
  else
    cout << "No";
  cout << endl;
  return 0;
}
#endif
