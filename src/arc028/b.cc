#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> xv(n);
  rep(i, n) cin >> xv[i];

  set<pair<int, int>> first, second;
  rep(i, n) {
    first.insert({xv[i], i + 1});
    if (i + 1 < k)
      continue;

    while (as_int(first.size()) > k) {
      second.insert(*first.rbegin());
      first.erase(prev(first.end()));
    }
    while (second.size() && first.rbegin()->first > second.begin()->first) {
      first.insert(*second.begin());
      second.insert(*first.rbegin());
      first.erase(prev(first.end()));
      second.erase(second.begin());
    }
    cout << first.rbegin()->second << endl;
  }

  return 0;
}
#endif
