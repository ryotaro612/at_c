#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> d(n, 0);
    for(int i = 0; i < n - 1; i++) {
        cout << "? " << 1 << " " << i + 2 << endl;
        cin >> d[i + 1];
    }
    int mx_i = 0, mx = 0;
    for(int i = 1; i < n; i++) {
        if(mx < d[i]) {
            mx = d[i];
            mx_i = i;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(mx_i == i)
            continue;
        cout << "? " << mx_i + 1 << " " << i + 1 << endl;
        int temp;
        cin >> temp;

        ans = max(temp, ans);
    }

    cout << "! " << ans << endl;

    return 0;
}
#endif