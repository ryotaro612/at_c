#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> xv(n), yv(m);
  rep(i, n) cin >> xv[i];
  xv.push_back(x);
  rep(i, m) cin >> yv[i];
  yv.push_back(y);
  int max_x = *max_element(xv.begin(), xv.end());
  int min_y = *min_element(yv.begin(), yv.end());
  if (min_y <= max_x) {
    cout << "War" << endl;
  } else {
    cout << "No War" << endl;
  }

  return 0;
}
#endif
