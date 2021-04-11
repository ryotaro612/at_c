#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> p(m);
    vector<string> s(m);
    for(int i = 0; i < m; i++)
        cin >> p[i] >> s[i];

    vector<ll> a(n + 1, 0ll);
    vector<bool> b(n + 1, false);
    for(int i = 0; i < m; i++) {
        if(s[i] == "AC") {
            b[p[i]] = true;
        } else if(!b[p[i]]) {
            a[p[i]]++;
        }
    }
    ll correct = 0ll, penalties = 0ll;
    for(int i = 0; i < n + 1; i++) {
        if(b[i]) {
            correct++;
            penalties += a[i];
        }
    }
    cout << correct << " " << penalties << endl;

    return 0;
}
#endif