#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _debug
int main() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 100; i <= 100 * n; i += 100) {
        for(int j = 1; j <= k; j++) {
            ans += i + j;
        }
    }
    cout << ans << endl;
    return 0;
}
#endif