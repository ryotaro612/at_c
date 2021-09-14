#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int a, int b, int c) {
    int mx = max(a, max(b, c));
    int sum = a + b + c;
    if((mx * 3 - sum) % 2 == 0) {
        return (mx * 3 - sum) / 2;
    } else {
        return ((mx + 1) * 3 - (sum + 1)) / 2 + 1;
    }
}

#ifndef _debug
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
    return 0;
}
#endif