#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifndef _debug
int main() {

    int a, b;
    cin >> a >> b;

    int ans = 1;
    for(int i = 0; i < a - b; i++) {
        ans *= 32;
    }
    cout << ans << endl;
    return 0;
}
#endif