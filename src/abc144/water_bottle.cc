#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

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
