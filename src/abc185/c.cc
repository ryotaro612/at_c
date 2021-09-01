#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<ll>> cache;

ll calc(int l, int cut) {
    if(cut == 0)
        return 1ll;
    if(l == 1)
        return 0ll;
    if(cache[l][cut] != -1)
        return cache[l][cut];
    return cache[l][cut] = calc(l - 1, cut) + calc(l - 1, cut - 1);
}
ll solve(int l) {
    cache = vector<vector<ll>>(l + 1, vector<ll>(12, -1));
    return calc(l, 11);
}

#ifndef _debug
int main() {
    int l;
    cin >> l;
    cout << solve(l) << endl;
}
#endif