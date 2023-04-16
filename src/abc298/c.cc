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

#ifdef ONLINE_JUDGE
int main() {
  int n, q;
  cin >> n >> q;
  vector<map<int, int>> box(n + 1), card(200001);
  rep(_, q) {
    int type, i;
    cin >> type >> i;
    if (type == 1) {
      int j;
      cin >> j;
      // cout << " type 1 " << i << " " << j << endl;
      box[j][i]++;
      card[i][j]++;
    } else if (type == 2) {
      vector<int> a;
      // cout << "type 2 "  << "  " << i << " size " << box[i].size() << endl;
      for (auto [c, freq] : box[i]) {
        rep(_, freq) a.push_back(c);
      }
      rep(i, a.size()) cout << a[i] << " \n"[i == as_int(a.size()) - 1];
    } else {
      vector<int> a;
      for (auto [c, freq] : card[i]) {
        a.push_back(c);
      }
      rep(i, a.size()) cout << a[i] << " \n"[i == as_int(a.size()) - 1];
    }
  }
  return 0;
}
#endif
