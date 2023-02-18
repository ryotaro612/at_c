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

int solve(int n, vector<int> &v) {
  vector<int> ones;
  rep(i, n) {
    if (v[i])
      ones.push_back(i);
  }
  if (ones.size() % 2)
    return -1;
  if (ones.size() == 0)
    return 0;
  if (ones.size() > 2 || ones[0] + 1 != ones[1])
    return ones.size() / 2;
  if (n == 3)
    return -1;
  if (n == 4 && ones[0] == 1 && ones[1] == 2) {
    return 3;
  } else {
    return 2;
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  rep(i, t) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> v(n, 0);
    rep(j, n) {
      if (s[j] == '1')
        v[j] = 1;
    }
    cout << solve(n, v) << endl;
  }
  return 0;
}
#endif
