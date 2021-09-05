#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _debug
int main() {
    string s, t;
    cin >> s >> t;
    vector<string> a = {s, t};

    sort(a.begin(), a.end());
    if(a[0] == s)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
#endif