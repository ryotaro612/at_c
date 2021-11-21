#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(int s, int t, int x) {
    if(s < t) {
        if(s <= x && x < t) {
            return "Yes";
        } else {
            return "No";
        }
    } else {
        if(s <= x || x < t)
            return "Yes";
        else
            return "No";
    }
}

#ifndef _debug
int main() {
    int s, t, x;
    cin >> s >> t >> x;
    cout << solve(s, t, x) << endl;
    return 0;
}
#endif