#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(string x) {
    string res;
    for(int i = 0; i < (int)x.size(); i++) {
        if(x[i] == '.')
            break;
        res.push_back((x[i]));
    }
    return res;
}

#ifndef _debug
int main() {
    string x;
    cin >> x;
    cout << solve(x) << endl;
    return 0;
}
#endif