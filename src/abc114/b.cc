#include <bits/stdc++.h>
#include <limits>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  int res = 10000000;
  for(int i = 2;i<(int) s.size();i++) {
    int temp = (s[i-2] - '0') * 100 + (s[i-1] - '0') * 10 + (s[i] - '0');
    res = min(res, abs(753 - temp));
  }
  cout << res << endl;
  return 0;
}
#endif
