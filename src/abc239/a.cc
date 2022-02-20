#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  ld h;
  cin >> h;
  cout << fixed << setprecision(12) << sqrt(h * ((ld)12800000 + h)) << endl;
  return 0;
}
#endif
