#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(a.begin(), a.end());
  int res = a[2] * 10;
  res += a[1] + a[0];
  cout << res << endl;
}
#endif
