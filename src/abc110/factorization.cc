#include <iostream>
#include <utility>
#include<vector>

using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


vector<pair<long long, long long>> prime_factor(long long m) {
  vector<pair<long long, long long>> a;
  for(long long i = 2; i*i<= m; i++) {
    long long c = 0;
    while(m % i == 0) {
      c++;
      m /= i;
    }
    if(c>0) {
      a.push_back(make_pair(i, c));
    }
  }
  if(m != 1) {
    a.push_back(make_pair(m, 1));
  }
  return a;
}

long long factorization(long long n, long long m) {
  COMinit();
  vector<pair<long long, long long>> ans = prime_factor(m);
  long long acc = 1;
  for(auto iter = ans.begin(); iter != ans.end(); ++iter) {
    pair<long long, long long> item = *iter;
    acc *= COM(item.second+(n-1), item.second) % MOD;
    acc %= MOD;
  }
  return acc;
}
/*
int main() {
  long long n, m;
  cin >> n;
  cin >> m;
  cout << factorization(n, m);
  return 0;
}
*/
