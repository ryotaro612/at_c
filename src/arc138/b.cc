#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];

  deque<int> que;
  for (auto e : av)
    que.push_back(e);

  int flip = 0;
  while (!que.empty()) {
    // 0 0 -> 0, 1 0 -> 1, 0 1 -> 1 , 1 1 -> 0
    if ((que.back() ^ flip) == 0) {
      que.pop_back();
      continue;
    } else if ((que.front() ^ flip) == 0) {
      que.pop_front();
      if (flip)
        flip = 0;
      else
        flip = 1;
    } else {
      break;
    }
  }
  if (que.empty())
    cout << "Yes";
  else
    cout << "No";

  cout << endl;
  return 0;
}
#endif
