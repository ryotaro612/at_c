#include <iostream>
#include <cmath>
#include "flipping_signs.h"

using namespace std;

long long flipping_signs(int n, long long a[]) {
  long long sum = 0;
  long long minimum = 1000000001;
  int num_minus = 0;
  for(int i=0;i<n;i++) {
    if(a[i] < 0)
      num_minus++;
    long long absolute = abs(a[i]);
    sum += absolute;
    minimum = min(absolute, minimum);
  }
  if(num_minus % 2 == 0)
    return sum;

  return sum - 2 * minimum;
}
/*
int main() {
  int n;  
  cin >> n;
  long long a[n];
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  long long ans = flipping_signs(n , a);
  cout << ans;
}
*/
