#include <bits/stdc++.h>
typedef long double ld;

using namespace std;

long double water_bottle( long double a, long double b, long double x){
  long double ans;
  if(a * a * b / 2.0 <= x) {
    ans = atan(2 * (a * a * b - x) / (a * a * a));
  } else {
    ans = M_PI / 2 - atan(2 * x / (a * b * b));
  }
  return ans * 180 /M_PI;
}
/*
int main() {
  ld a, b, x;
  cin >> a >> b >> x;
  cout << fixed << setprecision(10);
  cout << water_bottle(a, b, x);
}
*/
