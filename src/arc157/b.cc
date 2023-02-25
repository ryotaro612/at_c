#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <functional>
#include <queue>
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
  int n, k, n_x = 0;
  string s;
  cin >> n >> k >> s;
  for (auto c : s) {
    if (c == 'X')
      n_x++;
  }
  if (n_x < k) {
    for (auto &c : s) {
      if (c == 'X')
        c = 'Y';
      else
        c = 'X';
    }
    k = n - k;
  }
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      que;

  for (int i = 0, prev_y = -1; i < n; i++) {
    if (s[i] == 'Y') {
      if (prev_y != -1)
        que.push({i - prev_y, prev_y + 1, i});
      prev_y = i;
    }
  }
  while (k && !que.empty()) {
    auto [_, start, end] = que.top();
    que.pop();
    for (int i = start; i < end && k; i++) {
      s[i] = 'Y';
      k--;
    }
  }
  for (int i = 0; i < n && k && s[i] == 'X'; i++) {
    s[i] = 'Y';
    k--;
  }
  for (int i = n - 1; i >= 0 && k && s[i] == 'X'; i--) {
    s[i] = 'Y';
    k--;
  }
  int res = 0;
  rep(i, n) {
    if (i && s[i] == 'Y' && s[i - 1] == 'Y')
      res++;
  }
  cout << res << endl;
  return 0;
}
#endif
