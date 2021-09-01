#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(ll n) {
    int res = 0;
    for(ll i = 1; i < 10ll; i++) {
        if(10ll * i + i <= n)
            res++;
        else
            return res;
    }
    for(ll i = 10ll; i < 100ll; i++) {
        if(100ll * i + i <= n)
            res++;
        else
            return res;
    }
    for(ll i = 100ll; i < 1000ll; i++) {
        if(1000ll * i + i <= n)
            res++;
        else
            return res;
    }
    //cout << "8: current -> " << res << endl;
    for(ll i = 1000ll; i < 10000ll; i++) {
        if(10000ll * i + i <= n)
            res++;
        else
            return res;
    }
    //cout << "10" << endl;
    for(ll i = 10000ll; i < 100000ll; i++) {
        if(100000ll * i + i <= n)
            res++;
        else
            return res;
    }
    for(ll i = 100000ll; i < 1000000ll; i++) {
        if(1000000ll * i + i <= n)
            res++;
        else
            return res;
    }
    return res;
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif