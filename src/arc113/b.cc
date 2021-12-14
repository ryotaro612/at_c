#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int digit(ll n) { return n % 10ll; }

ll solve(ll a, ll b, ll c) {
    int aa = digit(a);
    if(aa == 0)
        return 0;

    vector<vector<int>> v(10);
    v[1] = {1, 1, 1, 1};
    v[2] = {6, 2, 4, 8};
    v[3] = {1, 3, 9, 7};
    v[4] = {6, 4, 6, 4};
    v[5] = {5, 5, 5, 5};
    v[6] = {6, 6, 6, 6};
    v[7] = {1, 7, 9, 3};
    v[8] = {6, 8, 4, 2};
    v[9] = {1, 9, 1, 9};

    if(b % 4 == 0)
        return v[aa][0];
    if(b % 4 == 1)
        return v[aa][1];
    if(b % 4 == 2) {
        if(c == 1)
            return v[aa][2];
        return v[aa][0];
    }
    // 3
    if(c % 2 == 0)
        return v[aa][1];
    return v[aa][3];
}

#ifdef ONLINE_JUDGE
int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
}
#endif