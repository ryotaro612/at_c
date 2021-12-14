#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(ll x, ll y) {
    ll current = x, res = 1;

    while(current * 2ll <= y) {
        res++;
        current *= 2ll;
        //cout << current << endl;
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    ll x, y;
    cin >> x >> y;
    cout << solve(x, y) << endl;
    return 0;
}
#endif