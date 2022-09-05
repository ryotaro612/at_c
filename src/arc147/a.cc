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
  multiset<ll> sa;
  rep(i, n) {
    ll a;
    cin >> a;
    sa.insert(a);
  }

  int result = 0;
  while (sa.size() > 1) {
    ll aj = *sa.begin();
    ll ai = *sa.rbegin();
    auto iter = sa.end();
    sa.erase(--iter);
    if (ai % aj != 0) {
      sa.insert(ai % aj);
    }
    // for (auto e : sa)
    //   cout << e << " ";
    // cout << endl;
    result++;
  }

  cout << result << endl;

  return 0;
}
#endif
