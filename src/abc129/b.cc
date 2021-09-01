#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for(int i = 0; i < n; i++)
        cin >> w[i];
    int ans = 100000000;
    for(int i = 0; i < n - 1; i++) {
        int s1 = 0;
        for(int j = 0; j <= i; j++) {
            s1 += w[j];
        }
        int s2 = 0;
        for(int j = i + 1; j < n; j++) {
            s2 += w[j];
        }
        ans = min(ans, abs(s1 - s2));
    }
    cout << ans << endl;

    return 0;
}
#endif