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
  int n;
  cin >> n;
  vector<string> sv(n), tv(n);
  rep(i, n) cin >> sv[i] >> tv[i];
  vector<bool> ok(n, false);
  queue<int> que;
  set<string> used(sv.begin(), sv.end());
  map<string, int> rev;
  rep(i, tv.size()) {
    rev[tv[i]] = i;
    if (used.find(tv[i]) == used.end()) {
      que.push(i);
    }
  }
  while (!que.empty()) {
    int i = que.front();
    que.pop();
    ok[i] = true;
    if (rev.find(sv[i]) != rev.end()) {
      int j = rev[sv[i]];
      que.push(j);
    }
  }
  rep(i, n) if (!ok[i]) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
#endif
