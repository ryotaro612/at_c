#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n - 1);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n - 1; i++)
        cin >> c[i];

    int ans = 0;
    for(auto bb : b)
        ans += bb;
    // cout << ans << endl;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] + 1 == a[i + 1])
            ans += c[a[i] - 1];
    }
    cout << ans << endl;
    return 0;
}
#endif