#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1000000007;

vector<int> calc_divisors(ll k) {
    vector<int> res;
    for(int i = 1; i * i <= k; i++) {
        if(k % i == 0) {
            res.push_back(i);
            if(i * i != k) {
                res.push_back(k / i);
            }
        }
    }
    return res;
}
vector<ll> factorization(ll n) {
    vector<ll> res;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n != 1) {
        res.push_back(n);
    }
    return res;
}

int bit_count(ll n) {
    ll count = 0;
    while(n != 0) {
        if(n & 1) {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

//　
ll calc(ll n, ll k) {
    vector<ll> fact = factorization(k);
    ll sum = 0;
    for(int m = 0; m < 1 << (int)fact.size(); m++) {
        ll va = 1;
        for(int i = 0; i < (int)fact.size(); i++) {
            if((m & (1 << i)) > 0) {
                va *= fact[i];
            }
        }
        ll from = va;
        ll to = (n / va) * va;
        ll num = n / va;
        ll part = (((((from + to) % MOD) * num) % MOD) * modinv(2, MOD)) % MOD;
        if(bit_count(m) % 2 == 1) {
            sum = sum - part;
            if(sum < 0)
                sum += MOD;
        } else {
            sum = (sum + part) % MOD;
        }
    }
    return sum;
}

ll solve(ll n, ll k) {
    vector<int> divisors = calc_divisors(k);
    ll res = 0;
    for(auto divisor : divisors) {
        res = (res + ((k * calc(n / divisor, k / divisor)) % MOD)) % MOD;
    }
    return res;
}
/*
int main() {
    ll n, k;
    cin >> n >> k;
    cout << solve(n, k);
}
*/