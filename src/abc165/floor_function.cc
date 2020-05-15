#include<iostream>
#include<algorithm>

using namespace std;

long long floor_function(long long a, long long b, long long n) {
  long long x = min(b-1, n);

  long long c = (a*x)/b;
  long long d = a * (x/b);
  return c-d;
}
/*
int main() {
  long long a, b, n;
  cin >> a;
  cin >> b;
  cin >> n;
  cout << floor_function(a, b, n);
}
*/
