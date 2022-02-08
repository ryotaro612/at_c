#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int k;
  cin >> k;

  int odd = 0, even = 0;
  for (int i = 1; i <= k; i++) {
    if (i % 2 == 0) {
      even++;
    } else {
      odd++;
    }
  }
  cout << odd * even << endl;

  return 0;
}
#endif
