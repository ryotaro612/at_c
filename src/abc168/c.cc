#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long double PI = 3.14159265358979323846264338327950L;

long double solve(long double a,long double b,long double h, long double m) {
  
  long double a_a = 360*(h/12) + 30 * (m/60);
  long double b_a = 360*(m/60);
  long double theta = a_a > b_a ? (a_a - b_a) : (b_a - a_a);
  if(theta == 180) {
    return a + b;
  }
  if(theta > 180) {
    theta = 360 - theta;
  }
  return sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(PI*theta/180));

}

int main() {
  long double a, b, h, m;
  cin >> a >> b >> h >> m;
  cout << fixed << setprecision(10) << solve(a, b, h, m); 
}
