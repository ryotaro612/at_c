#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<ll> h) {
    int ans = 0, temp = 0;

    for(int i = 0; i < n - 1; i++) {
        if(h[i] >= h[i + 1])
            temp++;
        else {
            ans = max(temp, ans);
            temp = 0;
        }
    }

    return max(temp, ans);
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];

    cout << solve(n, h) << endl;
    return 0;
}
#endif