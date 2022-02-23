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
  int r;
  cin >> r;
  if (r < 1200)
    cout << "ABC";
  else if (r < 2800)
    cout << "ARC";
  else
    cout << "AGC";
  cout << endl;
  return 0;
}
#endif
