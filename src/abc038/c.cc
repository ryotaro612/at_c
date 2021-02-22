#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<int> a) {
    ll l = 0ll, r = 0ll, res = 0ll;
    for(;;) {
        while(r < n - 1ll && a[r] < a[r + 1ll]) {
            r++;
        }
        res += (r - l + 1ll) * (r - l + 2ll) / 2ll;
        if(r == n - 1ll)
            break;
        l = ++r;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
}
#endif
