#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const static ll MOD = pow(10, 9) + 7;

ll solve(int n, string s1, string s2) {
    ll res = s1[0] == s2[0] ? 3 : 6;

    for(int i = 1; i < n; i++) {
        if(s1[i - 1] == s1[i] && s2[i - 1] == s2[i]) {
            continue;
        }
        if(s1[i - 1] == s2[i - 1] && s1[i] == s2[i]) {
            res = (2 * res) % MOD;
            continue;
        }
        if(s1[i] == s2[i] && s1[i - 1] != s2[i - 1]) {
            continue;
        }
        if(s1[i - 1] == s2[i - 1] && s1[i] != s2[i]) {
            res = (2 * res) % MOD;
            continue;
        }
        if(s1[i - 1] != s2[i - 1] && s1[i] != s2[i]) {
            res = (3 * res) % MOD;
            continue;
        }
    }
    return res;
}
/*
int main() {
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    cout << solve(n, s1, s2);
}
*/