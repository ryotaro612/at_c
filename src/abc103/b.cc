#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//#ifdef ONLINE_JUDGE
int main() {
  string s, t;
  cin >> s >> t;
  list<char> sl(s.begin(), s.end()), tl(t.begin(), t.end());

  for (int i = 0; i < (int)s.size(); i++) {
    if (sl == tl) {
      cout << "Yes" << endl;
      return 0;
    }
    char c = sl.front();
    sl.pop_front();
    sl.push_back(c);
  }
  cout << "No" << endl;

  return 0;
}
//#endif
