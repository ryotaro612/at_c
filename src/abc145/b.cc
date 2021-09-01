#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < n / 2; i++) {
        if(s[i] != s[n / 2 + i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
#endif