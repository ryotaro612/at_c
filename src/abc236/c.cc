#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<string> solve(int n, int m, vector<string> &sv, vector<string> &tv) {

  unordered_map<string, bool> express;
  for (auto t : tv) {
    express[t] = true;
  }
  vector<string> res(n);
  rep(i, n) {
    if (express[sv[i]])
      res[i] = "Yes";
    else
      res[i] = "No";
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> sv(n), tv(m);
  rep(i, n) cin >> sv[i];
  rep(i, m) cin >> tv[i];
  vector<string> res = solve(n, m, sv, tv);
  for (auto e : res)
    cout << e << endl;

  return 0;
}
#endif
