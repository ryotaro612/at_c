#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int a, int b, int x, int y) {
    if(a == b)
        return x;
    int diff = abs(a - b);
    if(a > b) {
        return min(x + (diff - 1) * y, (2 * diff - 1) * x);
    }
    return min(x + diff * y, (diff * 2 + 1) * x);
}

#ifndef _debug
int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << solve(a, b, x, y) << endl;
}
#endif