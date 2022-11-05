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
  vector<int> pv(n);
  rep(i, n) cin >> pv[i];
  int i = n - 2;
  set<pair<int, int>> st = {{pv[n - 1], n - 1}};
  while (pv[i] < (*st.begin()).first) {
    st.insert({pv[i], i});
    i--;
  }

  auto iter = st.lower_bound({pv[i], 0});
  iter--;
  // cout << pv[i] << " " << pv[(*iter).second] << endl;
  swap(pv[i], pv[(*iter).second]);
  vector<int> b;
  for (int j = i + 1; j < n; j++) {
    b.push_back(pv[j]);
  }
  int j = i + 1;
  sort(b.begin(), b.end(), greater<int>());
  for (auto e : b) {
    pv[j] = e;
    j++;
  }
  rep(i, n) {
    cout << pv[i];
    if (i == n - 1)
      cout << endl;
    else
      cout << " ";
  }

  return 0;
}
#endif
