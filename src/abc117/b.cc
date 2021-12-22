#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


string solve(int n, vector<int> &l) {
  rep(i, n) {
    int sum = 0;
    rep(j, n) {
      if(i != j)
	sum += l[j];
    }
    if(sum <= l[i])
      return "No";
  }
  return "Yes";
}


#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i, n) {
    cin >> l[i];
  }
  cout << solve(n, l) << endl;
  return 0;
}
#endif
