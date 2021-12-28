#include <bits/stdc++.h>
using namespace std;

string solve(int l, int r, string &s) {
  l--;
  reverse(s.begin() + l, s.begin()+r);
  return s;
}

#ifdef ONLINE_JUDGE
int main() {
  int l, r;
  string s;
  cin >> l >> r >> s;
  cout << solve(l, r, s) << endl;
  return 0;
}
#endif
