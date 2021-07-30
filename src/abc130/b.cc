#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    for(int i = 0; i < n; i++)
        cin >> l[i];

    int p = 0, ans = 1;
    for(int i = 0; i < n; i++) {
        p += l[i];
        if(p <= x)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
#endif