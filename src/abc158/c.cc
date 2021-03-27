#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int a, int b) {
    for(int i = 10; i < 1010; i++) {
        if((int)(0.08 * (double)i) == a && (int)(0.1 * (double)i) == b)
            return i;
    }
    return -1;
}

#ifndef _LOCAL
int main() {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
}
#endif