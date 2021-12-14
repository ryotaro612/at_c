#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(string s, string t) {
    if(s == t)
        return "Yes";
    map<char, char> mp, rev;
    for(int i = 0; i < (int)s.size(); i++) {
        if(mp[s[i]] == mp['_']) {
            mp[s[i]] = t[i];
        } else {
            if(mp[s[i]] != t[i])
                return "No";
        }
    }
    for(int i = 0; i < (int)s.size(); i++) {
        if(rev[t[i]] == rev['_']) {
            rev[t[i]] = s[i];
        } else {
            if(rev[t[i]] != s[i])
                return "No";
        }
    }
    return "Yes";
}

#ifdef ONLINE_JUDGE
int main() {
    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << endl;
    return 0;
}
#endif