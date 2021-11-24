#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(vector<int> &a) {
    int res = numeric_limits<int>::max();
    sort(a.begin(), a.end());
    do {
        int time = 0;
        for(auto dish : a) {
            while(time % 10 != 0)
                time++;
            time += dish;
        }
        res = min(time, res);
    } while(next_permutation(a.begin(), a.end()));

    return res;
}

#ifndef _debug
int main() {
    vector<int> a(5);
    rep(i, 5) cin >> a[i];
    cout << solve(a) << endl;
    return 0;
}
#endif