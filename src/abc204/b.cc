#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    for(auto aa : a) {
        if(aa <= 10)
            continue;
        ans += aa - 10;
    }

    cout << ans << endl;
    return 0;
}
#endif