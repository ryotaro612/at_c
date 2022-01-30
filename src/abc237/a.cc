#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  ll n;
  cin >> n;

  if (-2147483648ll <= n && n < 2147483648ll) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout << endl;
}
#endif
