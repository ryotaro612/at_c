#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    int n, k;
    cin >> n >> k;
    int res = 0;
    for(int i = 0; i < n; i++) {
        int h;
        cin >> h;
        if(h >= k)
            res++;
    }
    cout << res << endl;
    return 0;
}
#endif