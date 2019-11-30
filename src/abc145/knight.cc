#include <iostream>
#include <boost/math/special_functions/factorials.hpp>
using namespace std;

const long long MAX = 800000;
const long long MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void com_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long com(long long n, long long k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// // http://drken1215.hatenablog.com/entry/2018/06/08/210000
long long knight(long long x, long long y)  {
  com_init();
  if(((x+y) % 3) != 0)
    return 0;
  auto m = (2*x -y) /3;
  auto n = (2*y-x)/3;

  if (m < 0 || n < 0)
    return 0;
  auto ans = com(n+m, n);
  return ans % MOD;
}
