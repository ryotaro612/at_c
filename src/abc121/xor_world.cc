#include <iostream>

using namespace std;

long long solve(long long i) {
  if(i % 2 == 0) {
    long long num_of_one = i / 2;
    if(num_of_one % 2 == 0) {
      return i;
    }
    return i+1;
  }
  long long num_of_one = (i / 2) + 1;
  if(num_of_one % 2 == 0) {
    return 0;
  }
  return 1;
}

long long xor_world(long long a, long long b) {
  if(a == b)
    return a;

  if(a == 0)
    return solve(b);

  return solve(b) ^ solve(a-1);
}
/*
int main() {
  long long a,b;
  cin >> a;
  cin >> b;
  cout << xor_world(a, b);
}
*/

