#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll MOD = 1000000007;

ll solve(int n, vector<int> a) {
    vector<int> b(n, 0);
    for(auto aa : a) {
        b[aa]++;
    }
    if(n % 2 == 0) {
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0 && b[i] != 0)
                return 0ll;
            if(i % 2 == 1 && b[i] != 2)
                return 0ll;
        }
    } else { // 奇数
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                if(b[0] != 1)
                    return 0ll;
                else
                    continue;
            }
            if(i % 2 == 0 && b[i] != 2) {
                return 0ll;
            }
            if(i % 2 == 1 && b[i] != 0) {
                return 0ll;
            }
        }
    }
    ll res = 1;
    for(int i = 0; i < n / 2; i++) {
        res *= 2;
        res %= MOD;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
}
#endif