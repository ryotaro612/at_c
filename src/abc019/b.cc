#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    string s;
    cin >> s;
    string res;
    char c = s[0];
    int count = 1, index = 1;
    for(int i = 1; i < (int)s.size(); i++) {
        if(s[i] == c)
            count++;
        else {
            res.push_back(c);
            res = res + to_string(count);
            count = 1;
            c = s[i];
        }
    }
    res.push_back(c);
    res = res + to_string(count);
    cout << res << endl;
    return 0;
}
#endif