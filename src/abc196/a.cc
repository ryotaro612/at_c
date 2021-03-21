#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int a, int b, int c, int d) {
    int res = -10000000;
    for(int x = a; x <= b; x++) {
        for(int y = c; y <= d; y++) {
            res = max(res, x-y);
        }
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << solve(a, b, c, d) << endl;
    return 0;
}
#endif