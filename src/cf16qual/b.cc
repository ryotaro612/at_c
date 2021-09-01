#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    for(int i = 0; i < t; i++)
        cin >> a[i];
    if(t == 1) {
        cout << a[0] - 1 << endl;
        return 0;
    }

    sort(a.begin(), a.end(), greater<int>());
    if(a[0] <= k - a[0] + 1) {
        cout << 0 << endl;
        return 0;
    } else {
        cout << a[0] - (k - a[0] + 1) << endl;
        return 0;
    }

    return 0;
}
#endif