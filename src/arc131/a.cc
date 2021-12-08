#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll a, ll b) {
    string res_str = to_string(a) + "0" + to_string(b * 5ll);
    ll res = stoll(res_str);
    return res;
}

#ifndef _debug
int main() {
    ll a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}
#endif