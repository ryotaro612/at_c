#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s, string t) {
    string res = "You can win";
    set<char> atcoder = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == t[i])
            continue;
        if(s[i] == '@' && atcoder.find(t[i]) != atcoder.end())
            continue;
        if(t[i] == '@' && atcoder.find(s[i]) != atcoder.end())
            continue;
        res = "You will lose";
        break;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << endl;
    return 0;
}
#endif