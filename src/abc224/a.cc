#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(string s) {
    if(s[s.size() - 1] == 'r') {
        return "er";
    } else {
        return "ist";
    }
}

#ifndef _debug
int main() {
    string s;
	cin >> s;
    cout << solve(s) << endl;
    return 0;
}
#endif