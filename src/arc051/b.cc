#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

pair<int, int> temp(int k) { 
    if(k == 1) 
        return make_pair(2, 1);
    auto p = temp(k-1);
    return make_pair(p.first + p.second, p.first);
}
pair<ll, ll> solve(int k) { return temp(k); }

#ifndef _debug
int main() {
    int k;
    cin >> k;
    auto res = solve(k);
    cout << res.first << " " << res.second << endl;
    return 0;
}
#endif