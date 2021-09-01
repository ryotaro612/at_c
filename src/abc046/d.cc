#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s) {
    int n_g = 0;
    for(auto c : s) {
        if(c == 'g')
            n_g++;
    }
    int n = (int)s.size(), ans = 0;
    // cout << n_g << endl;
    while(n - n_g <= n_g) {
        // cout << n - n_g << " " << n_g << endl;
        if(n - (n_g - 1) <= (n_g - 1)) {
            ans++;
            n_g--;
        } else
            break;
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