#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int a, b;
  cin >> a >> b;
  for (int c = 1; c <= 3; c++) {
    int mul = a * b * c;
    if (mul % 2) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;

#endif
