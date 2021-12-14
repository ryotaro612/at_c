#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(ll n, ll y) {
    y /= 1000;
    for(int a = 0; a <= 2000; a++) {
        ll temp = y - n - 9 * a;
        if(temp % 4 == 0 && temp / 4 >= 0 && n - a - temp / 4 >= 0) {
            return {a, temp / 4, n - a - temp / 4};
        }
    }
    return {-1, -1, -1};
}

#ifdef ONLINE_JUDGE
int main() {
    ll n, y;
    cin >> n >> y;
    vector<ll> ans = solve(n, y);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    return 0;
}
#endif