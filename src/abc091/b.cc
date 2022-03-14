#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <unordered_map>
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  unordered_map<string, int> sv, tv;
  rep(i, n) {
    string s;
    cin >> s;
    sv[s]++;
  }
  int m;
  cin >> m;
  rep(i, m) {
    string s;
    cin >> s;
    tv[s]++;
  }

  int res = 0;
  for (pair<string, int> kv : sv) {
    string s = kv.first;
    res = max(res, kv.second - tv[s]);
  }
  cout << res << endl;
  return 0;
}
#endif
