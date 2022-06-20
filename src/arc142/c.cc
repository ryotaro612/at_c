#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

int solve(int n) {
  map<int, int> one;
  for (int i = 3; i <= n; i++) {
    cout << "? 1 " << i << endl;
    cin >> one[i];
  }
  vector<int> children;
  for (auto [node, d] : one) {
    if (d == 1) {
      children.push_back(node);
    }
  }
  if (children.size() == 0)
    return 1;
  map<int, int> two;
  for (int i = 3; i <= n; i++) {
    cout << "? 2 " << i << endl;
    cin >> two[i];
  }

  int min_dist = 1000000, min_node = -1;
  for (int child : children) {
    if (two[child] < min_dist) {
      min_node = child;
      min_dist = min(min_dist, two[child]);
    }
  }
  if (min_dist != 2) {
    return one[min_node] + two[min_node];
  }
  vector<int> three;
  for (int i = 3; i <= n; i++) {
    if (one[i] + two[i] == 3) {
      three.push_back(i);
    }
  }
  if (three.size() != 2) {
    return 1;
  }
  cout << "? " << three[0] << " " << three[1] << endl;
  int d;
  cin >> d;
  if (d == 1)
    return 3;
  else
    return 1;
}

//#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  int res = solve(n);
  cout << "! " << res << endl;
  return 0;
}
//#endif
