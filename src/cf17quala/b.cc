#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if((i * (m - j) + j * (n - i)) == k) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
#endif