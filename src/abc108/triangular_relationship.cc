#include<iostream>
#include "triangular_relationship.h"

using namespace std;

long long triangular_relationship(int n, int k) {
  if (k % 2 == 0) {
    long long a = n / k;
    long long b = (n + (k/2)) / k;
    return a*a*a + b*b*b;
  }
  long long a = n / k;
  return a*a*a;
}
/*
int main() {
    long long n, k;
    cin >> n >> k;
    cout << triangular_relationship(n, k);
}
*/
