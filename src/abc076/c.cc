#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

string solve(string s, string t) {
    int s_len = (int)s.size(), t_len = (int)t.size();
    for(int i = s_len - t_len; i >= 0; i--) {
#ifdef _LOCAL
        cout << "check " << i << endl;
#endif
        bool ok = true;
        for(int j = 0; j < t_len; j++) {
            if(s[i + j] != '?' && s[i + j] != t[j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            string res = string(s);
            res = regex_replace(res, regex("\\?"), "a");
            res = res.replace(i, t_len, t);
            return res;
        }
    }

    return "UNRESTORABLE";
}
#ifndef _LOCAL
int main() {
    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << endl;
}
#endif