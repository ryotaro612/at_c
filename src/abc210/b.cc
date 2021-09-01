#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _debug
int main() {
    int n;
    string s;
    cin >> n >> s;

    bool t = true;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(t) {
                cout << "Takahashi" << endl;
                return 0;
            } else {
                cout << "Aoki" << endl;
                return 0;
            }
        }
        t = !t;
    }
    return 0;
}
#endif