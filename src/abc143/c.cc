#include <bits/stdc++.h>
using namespace std;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res;
    for(int i = 0; i < n; i++) {
        if(i < n - 1) {
            if(s[i] == s[i + 1])
                continue;
            else
                res.push_back(s[i]);
        } else {
            res.push_back(s[i]);
        }
    }
    cout << res.size() << endl;
    return 0;
}
#endif
