#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int x, y;
    cin >> x >> y;
    vector<bool> a(3, false);
    a[x] = true;
    a[y] = true;
    if(x == y) {
        cout << y << endl;
        return 0;
    }
    for(int i = 0; i < 3; i++) {
        if(a[i] == false) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
#endif
