#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
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
  int n, q;
  cin >> n >> q;
  queue<int> not_called;
  rep(i, n) not_called.push(i + 1);
  priority_queue<int, vector<int>, greater<int>> called;
  vector<bool> gone(n + 1, false);

  rep(i, q) {
    int e;
    cin >> e;
    if (e == 1) {
      int node = not_called.front();
      not_called.pop();
      called.push(node);
    } else if (e == 2) {
      int x;
      cin >> x;
      gone[x] = true;
    } else {
      while (true) {
        int x = called.top();
        if (gone[x] == false) {
          cout << x << endl;
          break;
        } else {
          called.pop();
        }
      }
    }
  }
  return 0;
}
#endif
