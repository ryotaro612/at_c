#include <bits/stdc++.h>
using namespace std;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string res;
    for(int i = 0; i < n; i++) {
        res.push_back(s[i]);
        res.push_back(t[i]);
    }
    cout << res << endl;
    return 0;
}
#endif