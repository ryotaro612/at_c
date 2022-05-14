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
  int w;
  cin >> w;
  vector<int> res;
  for (int i = 1; i <= 99; i++)
    res.push_back(i);
  for (int i = 100; i <= 9900; i += 100)
    res.push_back(i);
  for (int i = 10000; i <= 990000; i += 10000)
    res.push_back(i);
  res.push_back(1000000);
  cout << res.size() << endl;
  rep(i, res.size()) {
    cout << res[i];
    if (i == static_cast<int>(res.size()) - 1)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
#endif
