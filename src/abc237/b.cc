#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<vector<ll>> solve(int h, int w, vector<vector<ll>> &av) {

  vector<vector<ll>> res(w, vector<ll>(h));
  rep(i, h) {
    rep(j, w) { res[j][i] = av[i][j]; }
  }

  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<ll>> av(h, vector<ll>(w));
  rep(i, h) {
    rep(j, w) { cin >> av[i][j]; }
  }
  vector<vector<ll>> res = solve(h, w, av);

  rep(i, w) {
    rep(j, h) {
      cout << res[i][j];
      if (j < h - 1)
        cout << " ";
    }
    cout << endl;
  }
}
#endif
