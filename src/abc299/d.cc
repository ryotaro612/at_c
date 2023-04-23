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
  int lb = -1, ub = n;
  while (ub - lb > 1) {
    int mid = (ub + lb) / 2;
    cout << "? " << mid + 1 << endl;
    int v;
    cin >> v;
    if (v == 0)
      lb = mid;
    else
      ub = mid;
  }
  cout << "! " << lb + 1 << endl;
  return 0;
}
#endif
