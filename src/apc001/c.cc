#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << 0 << endl;
    vector<string> fm(n, "");
    cin >> fm[0];
    if(fm[0] == "Vacant")
        return 0;
    cout << n - 1 << endl;
    cin >> fm[n - 1];
    if(fm[n - 1] == "Vacant")
        return 0;
    int l = -1, r = n;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        cout << mid << endl;
        cin >> fm[mid];
        if(fm[mid] == "Vacant")
            return 0;
        int c_l = max(0, l), c_r = min(n - 1, r);
        if((mid - c_l + 1) % 2 == 0) {
            if(fm[c_l] == fm[mid])
                r = mid;
            else
                l = mid;
        } else {
            if(fm[c_l] == fm[mid])
                l = mid;
            else
                r = mid;
        }
    }
    if(fm[r] == "") {
        cout << r;
    } else {
        cout << l;
    }
    return 0;
}
#endif
