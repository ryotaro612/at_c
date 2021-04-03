#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(string s) {
    string res;
    for(int i = 0; i < (int)s.size(); i++)
        res.push_back('x');
    return res;
}

#ifndef _LOCAL
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
}
#endif