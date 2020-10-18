#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, int k) {
  ll res = 0;
  //cout << "n: " << n << " k: " << k << endl;
  for (int b = 1;b<=n; b++) {
    if(k >= b) {
      continue;
    }
    int div = n / b;
    //cout << "b: " << b << " div: " << div << " per: " << b - k << " -> " << div * (b - k) << " ";
    res += div * (b - k);
    int tail = min(n, div * b + b - 1) - (div * b + k) + 1;
    //cout << "tail: " << tail << endl;
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