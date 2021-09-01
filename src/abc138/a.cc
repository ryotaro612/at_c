#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int a, string s) {
    if(a >= 3200)
        return s;
    return "red";
}

#ifndef _debug
int main() {
    int a;
    string s;
    cin >> a >> s;
    cout << solve(a, s) << endl;

    return 0;
}
#endif