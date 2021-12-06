#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(string &s) {
    string t;
    for(int i = 0; i < 30; i++) {
        char c;
        if(i % 3 == 0)
            c = 'o';
        else
            c = 'x';
        t.push_back(c);
    }
    rep(i, 3) {
        string substr = t.substr(i, (int)s.size());
        if(substr == s)
            return "Yes";
    }
    return "No";
}
#ifndef _debug
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
#endif