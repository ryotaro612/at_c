#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
    int a, b, t;
    cin >> a >> b >> t;
    int ans = 0;
    for(int i = a; i <= t; i += a) {
        ans += b;
    }
    cout << ans << endl;
    return 0;
}
#endif