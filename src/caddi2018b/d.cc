#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(int n, vector<ll> a) { 
    string res = "second";
    for(auto aa: a) {
        if(aa % 2 !=0)
            return "first";
    }
    return res; 
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
}
#endif