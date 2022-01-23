#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


vector<int> solve(int n, vector<int> &a) {
  int i = 0;
  for(;i<n;i++) {
    if(i == n-1)
      break;
    if(a[i] > a[i+1])
      break;
  }
  vector<int> res;
  for(auto e: a) {
    if(a[i] != e) {
      res.push_back(e);
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> res = solve(n, a);
  rep(i, res.size()) {
    cout << res[i];
    if(i == n-1)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
#endif
