#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int solve(int n, int k) {
  if (n % k == 0)
    return 0;
  return 1;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  cout << solve(n, k) << endl;
  return 0;
}
#endif
