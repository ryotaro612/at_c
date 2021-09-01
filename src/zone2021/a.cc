#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    int ans = 0;
    for(int i = 0; i <= 9; i++) {
        if(s[i] == 'Z' && s[i + 1] == 'O' && s[i + 2] == 'N' && s[i + 3] == 'e')
            ans++;
    }
    return ans;
}

#ifndef _debug
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
#endif