#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string solve(int n, int q, vector<int> &rv, vector<int> &cv, vector<int> &qr, vector<int> &qc) {
  string res;
  rep(i, q) {
    if(cv[--qc[i]] > n - rv[--qr[i]]) {
      res.push_back('#');
    } else {
      res.push_back('.');
    }
    cv[--qc[i]];
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, q;
  cin >> n;
  vector<int> rv(n), cv(n);
  rep(i, n) { cin >> rv[i]; }
  rep(i, n) { cin >> cv[i]; }
  cin >> q;
  vector<int> qr(q), qc(q);  
  rep(i, q) { cin >> qr[i] >> qc[i]; }

  cout << solve(n, q, rv, cv, qr, qc) << endl;
}
#endif
