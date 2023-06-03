#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<string> sv(n);
  vector<ll> av(n);
  rep(i, n) cin >> sv[i] >> av[i];
  ll a_min = *min_element(av.begin(), av.end());
  int start;
  rep(i, n) {
    if (a_min == av[i])
      start = i;
  }
  rep(i, n) {
    cout << sv[start] << endl;
    start++;
    start %= n;
  }

  return 0;
}
#endif
