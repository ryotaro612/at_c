#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(string s) {
    int n = (int)s.size();
    vector<int> prev(26, n);
    ll res = 0ll;
    for(int i = n - 3; i >= 0; i--) {
        if(s[i] == s[i + 1] && s[i] != s[i + 2]) {
            int last = prev[s[i] - 'a'];
            cout << "last -> " << last << endl;
            for(int j = 0; j < 26; j++) {
                cout << (char)('a' + j) << prev[j] << " ";
            }
            cout << endl;
            res += last - (i + 2);
            for(int i = 0; i < 26; i++)
                prev[i] = n;
            prev[s[i] - 'a'] = i;
        } else {
            prev[s[i + 2] - 'a'] = i + 2;

        }
    }
    return res;
}

#ifndef _LOCAL
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
}
#endif