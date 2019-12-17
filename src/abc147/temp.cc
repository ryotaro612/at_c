#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll MOD = 1000000007;
 
void solve() {
    int N;
    cin >> N;
    ll A[N];
    rep(i, N) cin >> A[i];
 
    ll result = 0;
    
    for(int i = 0; i < 60; ++i) {
        ll zero = 0;
        ll one = 0;
        for(int j = 0; j < N ; ++j) {
            if ((A[j] >> i) & 1LL) ++one;
            else ++zero;
        }
        // cout << "i" << i << endl;
        // cout << "one:" << one << endl;
        // cout << "zero" << zero << endl;
        result += (((one * zero) % MOD) * ((1LL << i) % MOD)) % MOD;
        // cout << "result" << result << endl;
    }
    result = result % MOD;
 
    cout << result << endl;
    return;
}
 
int main() {
    solve();
    return 0;
 
}
