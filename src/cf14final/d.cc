#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    ll a;
    cin >> a;
    cout << a + 1 << " " << 2 << endl;
    /*
    vector<vector<ll>> tri(10000, vector<ll>(10000, 0ll));
    tri[0][0] = 1ll;
    for(int y = 0; y < 10000; y++) {
        for(int x = 0; x <= y; x++) {
            if(x == 0) {
                tri[y][x] = 1ll;
            } else if(y == x) {
                tri[y][x] = 1ll;
            } else {
                tri[y][x] = tri[y - 1][x] + tri[y - 1][x - 1];
            }
        }
    }
    for(int y = 0; y < 10000; y++) {
        for(int x = 0; x <= y; x++) {
            if(tri[y][x] == a) {
                cout << y + 1 << " " << x + 1 << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1" << endl;
    */
    return 0;
}
#endif