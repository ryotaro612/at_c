#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum(vector<string> vals) {
    ll res = 0ll;
    for(auto v : vals) {
        res += stoll(v);
    }
    return res;
}

ll solve(string s) {
    ll res = 0ll;
    for(int i = 0; i < 1 << ((int)s.size() - 1); i++) {
        int prev = 0;
        vector<string> vals;
        for(int j = 0; (1 << j) <= i; j++) {
            if((1 << j) & i) {
                vals.push_back(s.substr(prev, j - prev + 1));
                prev = j + 1;
            }
        }
        vals.push_back(s.substr(prev, (int)s.size() - prev));
        res += sum(vals);
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
}
#endif