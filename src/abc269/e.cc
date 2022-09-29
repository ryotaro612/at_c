#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  int from = 1, to = n;

  while (from < to) {
    int mid = (from + to) / 2;
    cout << "? " << from << " " << mid << " " << 1 << " " << n << endl;
    int t;
    cin >> t;
    if (t == mid - from + 1)
      from = mid + 1;
    else
      to = mid;
  }
  assert(from == to);
  int x = from;
  from = 1, to = n;
  while (from < to) {
    int mid = (from + to) / 2;
    cout << "? " << 1 << " " << n << " " << from << " " << mid << endl;
    int t;
    cin >> t;
    if (t == mid - from + 1)
      from = mid + 1;
    else
      to = mid;
  }
  assert(from == to);
  cout << "! " << x << " " << from;
  return 0;
}
#endif
