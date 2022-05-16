#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<int> snake(int start, int delta, int end) {
  vector<int> res = {start};
  while (true) {
    int item = res.back() + delta;
    if (item <= 0 || item > end)
      break;
    res.push_back(item);
    if (delta > 0)
      delta++;
    else
      delta--;
    delta *= -1;
  }
  return res;
}
vector<int> zigzag(vector<int> &order) {
  vector<int> res;
  int n = order.size();
  if (n % 2 == 0) {
    int i = n / 2 - 1;
    int j = n / 2;
    while (i >= 0) {
      res.push_back(order[i]);
      res.push_back(order[j]);
      i--;
      j++;
    }
  } else {
    res.push_back(order[n / 2]);
    int i = n / 2 - 1;
    int j = n / 2 + 1;
    while (i >= 0) {
      res.push_back(order[i]);
      res.push_back(order[j]);
      i--;
      j++;
    }
  }
  return res;
}

vector<int> solve(int n, int x) {
  if (n % 2 == 0) {
    if (n / 2 == x) {
      return snake(n / 2, 1, n);
    } else if (n / 2 + 1 == x) {
      return snake(n / 2 + 1, -1, n);
    }
  } else {
    if (n / 2 + 1 == x)
      return snake(n / 2 + 1, 1, n);
  }
  vector<int> order;
  for (int i = 1; i <= n; i++)
    if (i != x)
      order.push_back(i);

  vector<int> res = {x};
  vector<int> zig = zigzag(order);
  for (auto z : zig)
    res.push_back(z);
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> res = solve(n, x);
  rep(i, res.size()) {
    cout << res[i];
    if (i == static_cast<int>(res.size()) - 1)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
#endif
