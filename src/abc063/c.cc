#include <bits/stdc++.h>
using namespace std;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];

    int ans = 0;
    sort(s.begin(), s.end());
    for(int i = 0; i < n; i++) {
        ans += s[i];
    }
    if(ans % 10 != 0) {
        cout << ans << endl;
        return 0;
    }

    int reduction = 101;
    for(int i = 0; i < n; i++) {
        if(s[i] % 10 != 0) {
            reduction = s[i];
            break;
        }
    }
    if(reduction == 101) {
        cout << 0 << endl;
        return 0;
    }
    cout << ans - reduction << endl;
    return 0;
}
#endif