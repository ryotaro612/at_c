#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int x, int y) {
  int res = 0, sum = x;
  while(sum < y) {
    sum += 10;
    res++;
  }
  return res;
}


#ifdef ONLINE_JUDGE
int main () {
  int x, y;
  cin >> x >> y;
  cout << solve(x, y) << endl;
  return 0;
}
#endif
