#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n, res = 0;
    cin >> n;
    vector<ll> p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];
    ll mini = p[0];
    for(int i = 0; i < n; i++) {
        if(p[i] <= mini) {
            res++;
            mini = p[i];
        }
    }
    cout << res << endl;
    return 0;
}
#endif