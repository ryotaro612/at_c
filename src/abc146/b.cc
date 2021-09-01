#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int n, string s) {
    string res;
    for(auto c : s) {
        char cc = ((c - 'A') + n) % 26 + 'A';
        res.push_back(cc);
    }
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(n, s) << endl;
    return 0;
}
#endif