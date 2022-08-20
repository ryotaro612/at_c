#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

string solve(int n, vector<ll> &av) {

  sort(av.begin(), av.end(), [](const ll &a, const ll &b) {
    string as(to_string(a)), bs(to_string(b));
    if (as.size() == bs.size()) {
      return b <= a;
    } else {
      return bs.size() <= as.size();
    }
  });
  vector<ll> cands = {av[0], av[1], av[2]};
  sort(cands.begin(), cands.end());
  string res = "";
  do {
    string cand =
        to_string(cands[0]) + to_string(cands[1]) + to_string(cands[2]);
    if (res == "")
      res = cand;
    else {
      // cout << res << " " << cand << endl;
      res = max(res, cand);
      // cout << res << endl;
    }

  } while (next_permutation(cands.begin(), cands.end()));
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, av) << endl;
  return 0;
}
#endif
