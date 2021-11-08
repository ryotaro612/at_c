#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifndef _debug
int main() {
    int l, r, d;
    cin >> l >> r >> d;
    int res = 0;
    for(int i = l; i <= r; i++)
        if(i % d == 0)
            res++;
    cout << res << endl;
    return 0;
}
#endif