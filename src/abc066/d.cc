#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k) {
    if(n < k)
        return 0;
    if(n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

vector<ll> solve(int n, vector<ll> a) {
    COMinit();
    vector<int> d(n + 1, -1);
    int l = 0, r = 0;
    for(int i = 0; i <= n; i++) {
        if(d[a[i]] == -1) {
            d[a[i]] = i;
            continue;
        }
        l = d[a[i]];
        r = i;
    }
    vector<ll> res(n + 1);
    for(int k = 1; k <= n + 1; k++) {
        res[k - 1] = COM(n + 1, k) - COM(n + 1 - 2 - (r - l - 1), k - 1);
        if(res[k - 1] < 0)
            res[k - 1] += MOD;
    }
    return res;
}
/*
int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for(int i = 0; i <= n; i++)
        cin >> a[i];
    auto r = solve(n, a);
    for(auto rr : r) {
        cout << rr << endl;
    }
}
*/