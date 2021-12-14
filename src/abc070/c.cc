#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

__int128 mygcd(__int128 a, __int128 b) {
    if(b == 0)
        return a;
    return mygcd(b, a % b);
}

__int128 mylcm(__int128 a, __int128 b) {
    __int128 aa, bb;
    if(a >= b) {
        aa = a;
        bb = b;
    } else {
        aa = b;
        bb = a;
    }
    return aa * bb / mygcd(aa, bb);
}

ll solve(int n, vector<ll> t) {

    __int128 ans = t[0];
    for(int i = 1; i < n; i++) {
        ans = mylcm(ans, t[i]);
    }
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> t(n);
    for(int i = 0; i < n; i++)
        cin >> t[i];

    cout << solve(n, t) << endl;
    return 0;
}
#endif