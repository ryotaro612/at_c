#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int a, int b) {
    int nyuuko = a + b;
    if(nyuuko >= 15 && b >= 8)
        return 1;
    if(nyuuko >= 10 && b >= 3)
        return 2;
    if(nyuuko >= 3)
        return 3;

    return 4;
}

#ifndef _debug
int main() {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}
#endif