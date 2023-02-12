#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  ll mask = 0;
  int n = s.size();
  for (int i = n - 1; i >= 0; i--) {
    mask = mask << 1;
    if (s[i] == 'o')
      mask += 1;
  }
  mask = (mask << (2 * n)) | (mask << n) | mask;
  int result = 10;
  rep(i, 1 << n) {
    ll temp = 0;
    int count = 0;
    rep(j, n) {
      if (i & (1 << j)) {
        count++;
        temp |= (mask << j);
      }
    }
    if (((temp >> (n * 2)) & ((1 << n) - 1)) == (1 << n) - 1) {
      result = min(result, count);
    }
  }
  cout << result << endl;

  return 0;
}
#endif
