#include<vector>
#include<iostream>
#include<array>
#include <iostream>

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

std::vector<long long> solve_blue_and_red_balls(int n, int k) {
    COMinit();
    vector<long long> ans(k);
    for(int i = 1;i<=k;i++) {
      //cout << "=====" << endl;
      //cout << "n-k+1: " << n-k+1 << " " << " i: " << i << " -> " << COM(n-k+1, i) << endl;
      //cout << "k-1: " << k-1 << " " << " i-1: " << i -1 << " -> " << COM(k-1, i-1) << endl;
      ans[i-1] = (COM(n-k+1, i) * COM(k-1, i-1)) % MOD;
      //cout << "ans " << i << " -> " << ans[i-1] << endl;
      //cout << "=====" << endl;
    }

    return ans;
}
/*
int main() {
    int n, k;
    cin >> n;
    cin >> k;
    vector<long long> ans = solve_blue_and_red_balls(n, k);
    for(int i=0;i<k;i++) {
      cout << ans[i] << endl;
    }
}
*/
