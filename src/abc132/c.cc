#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i = 0; i < n; i++)
        cin >> d[i];

    ll lb = 0, ub = 100001;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2ll, count = 0ll;
        for(int i = 0; i < n; i++) {
            if(d[i] < mid)
                count++;
        }
        if(count < n - count) {
            lb = mid;
        } else { // count >= n-count
            ub = mid;
        }
    }
    // cout << ub << " " << lb << endl;

    ll lb1 = 0, ub1 = 100001;
    while(ub1 - lb1 > 1) {
        ll mid = (ub1 + lb1) / 2ll, count = 0ll;
        for(int i = 0; i < n; i++) {
            if(d[i] < mid)
                count++;
        }
        if(count > n - count) {
            ub1 = mid;
        } else { // count >= n-count
            lb1 = mid;
        }
    }
    cout << ub1 - ub << endl;
    return 0;
}
#endif