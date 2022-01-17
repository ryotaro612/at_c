#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0;i<(int)(n);i++)
#ifdef ONLINE_JUDGE
int main() {
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> hv(n);
  rep(i, n)
    cin >> hv[i];

  int res = 0;
  for(int i=1;i<n;i++) {
    ld current = (ld)t - (ld) hv[i] * (ld)0.006;
    ld best = (ld)t - (ld) hv[res] * (ld)0.006;
    if(abs(current - a)< abs(best - a)) {
      res = i;
    }
  }
  cout << res + 1 << endl;
  return 0;
}
#endif
