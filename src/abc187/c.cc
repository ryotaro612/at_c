#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(int n, vector<string> s) {
    map<string, bool> mp, mp1;
    for(auto ss : s) {
        string key = ss[0] == '!' ? ss.substr(1) : ss;
        if(ss[0] == '!')
            mp1[key] = true;
        else
            mp[key] = true;

        if(mp1[key] && mp[key])
            return key;
    }

    return "satisfiable";
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];
    cout << solve(n, s) << endl;
}
#endif