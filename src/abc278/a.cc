#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <deque>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  deque<int> que;
  rep(i, n) {
    int a;
    cin >> a;
    que.push_back(a);
  }
  rep(i, k) {
    que.pop_front();
    que.push_back(0);
  }
  while (que.size()) {
    cout << que.front();
    que.pop_front();
    if (que.size())
      cout << " ";
  }
  cout << endl;

  return 0;
}
#endif
