#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const ll MOD = 998244353ll;
const int MAX = 510000;

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

ll solve(string &s) {
  COMinit();
  vector<int> chars(26, 0);
  for (auto &c : s)
    chars[c - 'a']++;
  vector<ll> lengths(s.size() + 1, 0ll);
  lengths[0] = 1ll;
  for (ll num_of_char : chars) {
    //cout << num_of_char << " chars" << endl;
    vector<ll> delta_lengths(lengths.size(), 0ll);
    for (ll i = 1ll; i <= num_of_char; i++) {
      for (ll j = 0ll; j < (ll)lengths.size(); j++) {
        delta_lengths[j + i] += COM(j + i, i) * lengths[j] % MOD;
        delta_lengths[j + i] %= MOD;
      }
    }
    //cout << "doge###" << endl;
    rep(i, lengths.size()) {
      lengths[i] += delta_lengths[i];
      lengths[i] %= MOD;
    }
  }
  //  cout << "doge" << endl;
  ll res = 0ll;
  for (int i = 1; i < (int)lengths.size(); i++) {
    res += lengths[i];
    res %= MOD;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}
#endif
