#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(string &s1, string &s2) {
    int count = 0;
    for(auto s : {s1, s2})
        for(auto c : s)
            if(c == '#')
                count++;
    if(count == 4 || count == 3)
        return "Yes";
    if(s1[0] == '#' && s2[1] == '#' || s1[1] == '#' && s2[0] == '#') {
        return "No";
    }
    return "Yes";
}

#ifndef _debug
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << solve(s1, s2) << endl;
    return 0;
}
#endif