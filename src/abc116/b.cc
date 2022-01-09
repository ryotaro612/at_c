#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int f(int n) {
  if (n % 2 == 0)
    return n / 2;
  else
    return 3 * n + 1;
}

int solve(int s) {
  int MX = 1000000;
  vector<bool> done(MX + 1, false);
  int a = s;
  done[a] = true;  
  for(int i = 2;i<=MX;i++) {
    a = f(a);
    if(done[a])
      return i;
    done[a] = true;
  }
  assert(false);
}
#ifdef ONLINE_JUDGE
int main() {
  int s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}
#endif
