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
  if (s[0] != 'A') {
    cout << "WA" << endl;
    return 0;
  }
  int num_c = 0;
  for (int i = 2; i < (int)s.size() - 1; i++) {
    if (s[i] == 'C')
      num_c++;
  }
  if (num_c != 1) {
    cout << "WA" << endl;
    return 0;
  }
  int num_lower = 0;
  for (auto c : s) {
    if ('a' <= c && c <= 'z')
      num_lower++;
  }
  if (num_lower == (int)s.size() - 2)
    cout << "AC";
  else
    cout << "WA";
  cout << endl;
  return 0;
}
#endif
