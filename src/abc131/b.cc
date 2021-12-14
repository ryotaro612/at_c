#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {

    int n, l;
    cin >> n >> l;

    ll all = 0ll;
    for(int i = 1; i <= n; i++) {
        all += l + i - 1;
    }
    int ans;
    for(int i = 1; i <= n; i++) {
        ll temp = 0ll;
        for(int j = 1; j <= n; j++) {
            if(i == j)
                continue;
            temp += l + j - 1;
        }
        if(i == 1) {
            ans = temp;
        } else {
            if(abs(all - temp) < abs(all - ans))
                ans = temp;
        }
    }
    cout << ans << endl;
    return 0;
}
#endif