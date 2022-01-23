#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  int a, b;
  cin >> a >> b;
  swap(s[a - 1], s[b - 1]);
  cout << s << endl;
  return 0;
}
#endif
