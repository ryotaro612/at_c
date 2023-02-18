#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

const ll MAX = 510000ll;
const ll MOD = 998244353ll;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k) {
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

#ifdef ONLINE_JUDGE
int main() {
  COMinit();
  int n, k;
  cin >> n >> k;
  set<int> as;
  rep(i, n) {
    int a;
    cin >> a;
    as.insert(a);
  }
  ll res = 0ll;
  ll next_seq = 0;
  for (int i = 0; i <= k; i++) {
    while (as.find(next_seq) != as.end()) {
      next_seq++;
    }
    if (next_seq) {
      res += COM(k - i + next_seq - 1, k - i);
      res %= MOD;
    }
    next_seq++;
  }

  cout << res << endl;
  return 0;
}
#endif
