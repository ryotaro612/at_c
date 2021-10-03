#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifndef _debug
int main() {

    string s, t;
    cin >> s >> t;
    if(s == t) {
        cout << "Yes" << endl;
        return 0;
    }
    int n = s.size();
    rep(i, n - 1) {
        string new_s = string(s);
        swap(new_s[i], new_s[i + 1]);
        if(new_s == t) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
#endif