#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll solve(int n, int m, vector<string> s) {
    ll even = 0ll, odd = 0ll;
    for(int i = 0; i < n; i++) {
        if(bitset<20>(s[i]).count() % 2 == 0)
            even++;
        else
            odd++;
    }
    return even * odd;
}

#ifndef _debug
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];
    cout << solve(n, m, s) << endl;
}
#endif