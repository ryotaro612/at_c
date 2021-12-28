#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template <typename T> void debug_vector(vector<T> v) {
  cout << "[";
  rep(i, v.size()) { cout << v[i] << ","; }
  cout << "]" << endl;
}

string solve(string &x) {
  string res;
  vector<ll> digits(10, 0ll);
  rep(i, x.size()) { digits[x[i] - '0']++; }
  //debug_vector(digits);
  int d = 0;
  for (int i = (int)x.size() - 1; i >= 0; i--) {
    rep(j, 10) { d += digits[j] * j; }
    //cout << i << " -> " << d % 10 << " carry " << d / 10 << endl;
    digits[x[i] - '0']--;
    //debug_vector(digits);
    res.push_back(d % 10 + '0');
    d = d / 10;
  }
  if (d > 0)
    res.push_back(d + '0');

  reverse(res.begin(), res.end());
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  string x;
  cin >> x;
  cout << solve(x) << endl;
  return 0;
}
#endif
