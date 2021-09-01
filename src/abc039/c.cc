#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    string s;
    cin >> s;
    map<int, pair<string, char>> mp;
    mp[0] = make_pair("Do", 'W');
    mp[1] = make_pair("Do", 'B');
    mp[2] = make_pair("Re", 'W');
    mp[3] = make_pair("Re", 'B');
    mp[4] = make_pair("Mi", 'W');
    mp[5] = make_pair("Fa", 'W');
    mp[6] = make_pair("Fa", 'B');
    mp[7] = make_pair("So", 'W');
    mp[8] = make_pair("So", 'B');
    mp[9] = make_pair("La", 'W');
    mp[10] = make_pair("La", 'B');
    mp[11] = make_pair("Si", 'W');
    for(int i = 0; i <= 11; i++) {
        bool ok = true;
        for(int j = 0; j < 20; j++) {
            if(mp[(i + j) % 12].second != s[j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << mp[i].first << endl;
        }
    }

    return 0;
}
#endif