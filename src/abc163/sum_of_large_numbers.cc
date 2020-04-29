#include <iostream>

using namespace std;

const long long MOD = 1000000007;

long long sum_of_large_numbers(long long n, long long k) {
  long long ans = 0;

  for(long long i=k;i<=n+1;i++) {
    long long minimum = ((i-1)*i)/2;
    long long maximum = ((n+n-i+1)*i)/2;
    long long add = maximum - minimum + 1;
    ans = (ans + add) % MOD;
  }
  return ans;
}

/**
int main() {
  long long n, k;
  cin >> n;
  cin >> k;
  cout << sum_of_large_numbers(n, k);
}

*/
