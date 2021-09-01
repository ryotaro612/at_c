#include <bits/stdc++.h>
using namespace std;

#ifndef _debug
int main() {
    string s;
    cin >> s;
    vector<string> chunk;
    string temp = "";
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '+') {
            if(temp != "") {
                chunk.push_back(temp);
                temp = "";
            }
        } else if(s[i] == '*') {
            continue;
        } else {
            temp.push_back(s[i]);
        }
    }
    if(temp != "")
        chunk.push_back(temp);
        /*
    for(auto c: chunk)
        cout << c << endl;
        */
    int ans = 0;
    for(auto s : chunk) {
        bool ok = false;
        for(auto c : s) {
            if(c == '0') {
                ok = true;
                break;
            }
        }
        if(!ok)
            ans++;
    }
    cout << ans << endl;

    return 0;
}
#endif
