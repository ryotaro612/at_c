#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  int san = 0, han = 0;
  rep(i, n) {
    string s;
    cin >> s;
    if (s == "For")
      san++;
    else
      han++;
  }
  if (san > han)
    cout << "Yes";
  else
    cout << "No";
  cout << endl;
  return 0;
}
#endif
