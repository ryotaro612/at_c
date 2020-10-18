#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, int k) {
  ll res = 0;
  for (int b = 1;b<=n; b++) {
    if(k >= b) {
      continue;
    }
    int div = n / b;
    res += div * (b - k);
    int tail = min(n, div * b + b - 1) - (div * b + k) + 1;
    if(k == 0) {
      res--;
    }
    if (tail > 0) {
      res += tail;
    }
  }
  return res;
}
/*
int main() {
  int n, k;
  cin >> n >> k;
  cout << solve(n, k);
}
*/