#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    string s;
    cin >> s;
    string ans = "Yes";
    for(int i = 0; i < (int)s.size(); i++) {
        if(i % 2 == 0 && s[i] == 'L')
            ans = "No";
        if(i % 2 == 1 && s[i] == 'R')
            ans = "No";
    }
    cout << ans << endl;
    return 0;
}
#endif