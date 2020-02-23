#include <iostream>
using namespace std;
/*
 * https://algo-logic.info/combination/
 */
const int MOD = 1000000007;


long long r_seq(long long x, long long p) {
  if(p==0)
    return 1;
  if(p % 2 == 0) {
    long long partial = r_seq(x, p/2);
    return ((partial % MOD) * (partial % MOD)) % MOD;
  }
  long long a = r_seq(x, p-1) % MOD;
  return ((x % MOD) * a) % MOD;
}

long long fact(long long start, long long end) {
  long long temp = 1;
  for (long long i= start;i<=end;i++) {
    temp *= i;
    temp %= MOD;
  }
  return temp % MOD;
}
long long qpow(long long a, long  long b, long long res){ //a^b
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
};
long long getC(long long n, long long x) {
	if (x > n) return 0;
	long long res1 = 1, res2 = 1;
	for (long long i = n; i >= n - x + 1; i--) res1 = res1 * i % MOD;
	for (long long i = x; i >= 1; i--) res2 = res2 * i % MOD;
	return res1 * qpow(res2, MOD - 2, 1) % MOD;
};

long long bouquet(long long n, int a, int b) {
  long long all = (r_seq(2, n) - 1) % MOD;
  long long nac = fact(n-a+1, n);
  long long ac = fact(1, a);
  long long comb_a = (nac * r_seq(ac, MOD-2)) % MOD;
  long long nbc = fact(n-b+1, n);
  long long bc = fact(1, b);
  long long comb_b = (nbc * r_seq(bc, MOD-2)) % MOD;
  long long sum = (comb_a + comb_b) % MOD;
  return ((all - sum) % MOD + MOD) % MOD;
}
/*
int main() {
  long long n;
  int a, b;
  cin >> n;
  cin >> a;
  cin >> b;
  cout << bouquet(n, a, b);
}
*/
