#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int a, b;
    cin >> a >> b;
    if(b == 1) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1;; i++) {
        if(a + (i - 1) * (a - 1) >= b) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
#endif