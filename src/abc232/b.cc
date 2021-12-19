#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(string &s, string &t) {
    rep(i, 26) {
        string a;
        rep(j, s.size()) {
            int code = s[j] - 'a';
            code = (code + i) % 26;
            a.push_back(code + 'a');
        }
        //cout << a << endl;
        if(a == t) {
            //cout << i << endl;
            //cout << a << endl;
            return "Yes";
        }
    }
    return "No";

    // vector<int> d;
    // int diff = t[0] + 26 - s[0];

    // for(int i = 1; i < (int)s.size(); i++)
    //     if(t[i] + 26 - s[i] != diff)
    //         return "No";

    // return "Yes";
}

#ifdef ONLINE_JUDGE
int main() {
    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << endl;
    return 0;
}
#endif