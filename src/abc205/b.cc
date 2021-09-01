#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    string ans = "Yes";

    for(int i = 1; i <= n; i++) {
        if(i != a[i - 1])
            ans = "No";
    }
    cout << ans << endl;
    return 0;
}
#endif