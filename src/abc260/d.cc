#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<int> solve(int n, int k, vector<int> &pv) {
  map<int, unordered_set<int> *> mp;
  vector<int> res(n, -1);
  rep(i, n) {
    // cout << "turn " << i << endl;
    // for (auto e : mp) {
    //   cout << e.first << " -> ";
    //   for (auto aa : e.second) {
    //     cout << aa << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    int x = pv[i];
    auto found = mp.upper_bound(x);
    if (found == mp.end()) {
      mp[x] = new unordered_set<int>();
      mp[x]->insert(x);
      if ((int)mp[x]->size() == k) {
        res[x - 1] = i + 1;
        delete mp[x];
        mp.erase(x);
      }
    } else {
      int key = found->first;
      found->second->insert(x);
      if ((int)mp[key]->size() == k) {
        for (auto p : *found->second) {
          res[p - 1] = i + 1;
        }
        delete mp[key];
        mp.erase(key);
      } else {
        mp[x] = found->second;
        mp.erase(key);
      }
    }
  }
  // cout << "---- " << endl;
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> pv(n);
  rep(i, n) cin >> pv[i];
  vector<int> res = solve(n, k, pv);
  rep(i, n) cout << res[i] << endl;
  return 0;
}
#endif
