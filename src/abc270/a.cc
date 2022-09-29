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
  int a, b;
  cin >> a >> b;
  map<int, set<char>> mp;
  mp[1] = {'A'};
  mp[2] = {'B'};
  mp[3] = {'A', 'B'};
  mp[4] = {'C'};
  mp[6] = {'B', 'C'};
  mp[5] = {'A', 'C'};
  mp[7] = {'A', 'B', 'C'};

  set<char> cs;
  for (auto e : mp[a])
    cs.insert(e);
  for (auto e : mp[b])
    cs.insert(e);
  map<char, int> doge;
  doge['A'] = 1;
  doge['B'] = 2;
  doge['C'] = 4;
  int res = 0;
  for (auto e : cs)
    res += doge[e];
  cout << res << endl;

  return 0;
}
#endif
