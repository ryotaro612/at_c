#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//#ifdef ONLINE_JUDGE
int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int vx = x2 - x1, vy = y2 - y1;
  int temp = vx;
  vx = -vy;
  vy = temp;
  int x3 = x2 + vx, y3 = y2 + vy;
  temp = vx;
  vx = -vy;
  vy = temp;
  int x4 = x3 + vx, y4 = y3 + vy;

  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  return 0;
}
//#endif
