#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];

    int res = 0;
    while(true) {
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(h[i] != 0)
                ok = false;
        }
        if(ok)
            break;

        int l, r;
        for(l = 0; l < n; l++) {
            if(h[l] != 0)
                break;
        }
        for(r = l; r < n; r++) {
            if(h[r] == 0)
                break;
        }
        int water = 2000;
        for(int i = l; i < r; i++)
            water = min(water, h[i]);
        for(int i = l; i < r; i++) {
            h[i] -= water;
        }
        res += water;
    }
    cout << res << endl;

    return 0;
}
#endif