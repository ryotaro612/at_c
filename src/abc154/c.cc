#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(int n, vector<ll> a) {
    set<ll> b;
    for(auto aa : a) {
        if(b.find(aa) != b.end())
            return "NO";
        b.insert(aa);
    }
    return "YES";
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
}
#endif