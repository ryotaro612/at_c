#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<ll> solve(int n, vector<ll> &a) {

    vector<ll> sums(n, 0ll), max_value(n);
    rep(i, n) {
        if(i == 0) {
            sums[0] = a[i];
            max_value[0] = a[i];
        } else {
            sums[i] = sums[i - 1] + a[i];
            max_value[i] = max(max_value[i - 1], a[i]);
        }
    }
    vector<ll> ans(n);
    ll acc = 0ll;
    rep(i, n) {
        ans[i] = acc + sums[i] + max_value[i] * (i + 1);
        acc += sums[i];
    }
	return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    auto ans = solve(n, a);
    for(auto e : ans)
        cout << e << endl;
    return 0;
}
#endif