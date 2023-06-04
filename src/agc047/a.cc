#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
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
  vector<ll> pv2(n, 0), pv5(n, 0);
  map<pair<ll, ll>, ll> counter;
  rep(i, n) {
    string s;
    cin >> s;
    size_t f = s.find('.');
    if (f == string::npos)
      s.push_back('.');
    f = s.find('.');
    s.erase(begin(s) + f);
    for (int j = s.size() - f; j < 9; j++)
      s.push_back('0');
    // cout << s << endl;
    ll v = stoll(s);
    while (v % 2ll == 0) {
      v /= 2ll;
      pv2[i]++;
    }
    while (v % 5ll == 0) {
      v /= 5ll;
      pv5[i]++;
    }
    counter[{pv2[i], pv5[i]}]++;
  }
  ll res = 0ll;
  rep(i, n) {
    counter[{pv2[i], pv5[i]}]--;
    for (auto [k, freq] : counter) {
      if (k.first + pv2[i] >= 18 && k.second + pv5[i] >= 18) {
        res += freq;
      }
    }
  }
  cout << res << endl;
  return 0;
}
#endif
