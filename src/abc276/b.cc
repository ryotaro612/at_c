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
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> mp;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    mp[a - 1].push_back(b);
    mp[b - 1].push_back(a);
  }
  rep(j, n) {
    auto v = mp[j];
    sort(v.begin(), v.end());
    cout << v.size();
    if (v.size() > 0) {
      rep(i, v.size()) { cout << " " << v[i]; }
    }
    cout << endl;
  }
  return 0;
}
#endif
