#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <string>
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool is_palindrome(string &s) {
  int n = static_cast<int>(s.size());
  // a b c -> 0
  // a b c d -> 0 1
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i])
      return false;
  }
  return true;
}

//#ifdef ONLINE_JUDGE
int main() {
  int a, b;
  cin >> a >> b;
  int res = 0;
  for (int i = a; i <= b; i++) {
    string s = to_string(i);
    if (is_palindrome(s)) {
      res++;
    }
  }
  cout << res << endl;
  return 0;
}
//#endif
