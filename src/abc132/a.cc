#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    for(auto c : s)
        mp[c]++;

    if(mp.size() != 2) {
        cout << "No" << endl;
        return 0;
    }
    for(auto p : mp) {
        if(p.second != 2) {
            cout << "No" << endl;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
#endif