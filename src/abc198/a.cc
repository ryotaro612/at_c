#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(string s) {
    string res;
    res.push_back(s[1]);
    res.push_back(s[2]);
    res.push_back(s[0]);
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    cout << n - 1 << endl;
    return 0;
}
#endif