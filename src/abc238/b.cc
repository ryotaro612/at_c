#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int solve(int n, vector<int> &av) {

  int current = 0;
  vector<int> cuts = {current};
  for (int a : av) {
    current += a;
    current %= 360;
    cuts.push_back(current);
  }
  sort(cuts.begin(), cuts.end());
  int res = 0;
  for (int i = 0; i < (int)cuts.size() - 1; i++) {
    res = max(res, cuts[i + 1] - cuts[i]);
  }
  res = max(res, 360 - cuts.back());
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, av) << endl;
  return 0;
}
#endif
