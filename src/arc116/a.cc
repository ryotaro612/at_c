#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<string> solve(int t, vector<ll> cases) {
    vector<string> res(t);
    for(int i = 0; i < t; i++) {
        if(cases[i] % 4 == 0)
            res[i] = "Even";
        else if(cases[i] % 2 == 0)
            res[i] = "Same";
        else
            res[i] = "Odd";
    }
    return res;
}

#ifndef _debug
int main() {
    int t;
    cin >> t;
    vector<ll> cases(t);
    for(int i = 0; i < t; i++)
        cin >> cases[i];
    vector<string> res = solve(t, cases);
    for(auto aa : res)
        cout << aa << endl;
}
#endif