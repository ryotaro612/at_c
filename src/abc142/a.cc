#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#ifndef _debug
int main() {
    int n, count = 0, odd = 0;
    cin >> n;

    for(int i = n; i >= 1; i--) {
        count++;
        if(i % 2 == 1)
            odd++;
    }
    cout << fixed << setprecision(12) << (ld)odd / (ld)count << endl;
    return 0;
}
#endif