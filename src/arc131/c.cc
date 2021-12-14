#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(int n, vector<ll> &a) {
    if(n % 2 == 1)
        return "Win";
    ll x = 0ll;
    rep(i, n) x ^= a[i];
    rep(i, n) {
        if(a[i] == x)
            return "Win";
    }
    return "Lose";
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> av(n);
    rep(i, n) cin >> av[i];
    cout << solve(n, av) << endl;
    return 0;
}
#endif