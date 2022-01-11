#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i= 0;i<(int)(n);i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n)
    cin >> p[i];

  int sum = 0;
  int mx = -1;
  rep(i, n) {
    sum += p[i];
    mx = max(mx, p[i]);
  }
  sum -= mx / 2;
  cout << sum << endl;
  return 0;
}
#endif
