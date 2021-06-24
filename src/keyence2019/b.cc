#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(string s, string sub, int from) {

    for(int i = 0; i < (int)sub.size(); i++) {
        if(s[from + i] != sub[i])
            return false;
    }
    return true;
}

#ifndef _LOCAL
int main() {
    string s;
    cin >> s;

    if(comp(s, "keyence", 0))
        cout << "YES";
    else if(comp(s, "k", 0) && comp(s, "eyence", (int)s.size() - 6)) {
        cout << "YES";
    } else if(comp(s, "ke", 0) && comp(s, "yence", (int)s.size() - 5)) {
        cout << "YES";
    } else if(comp(s, "key", 0) && comp(s, "ence", (int)s.size() - 4)) {
        cout << "YES";
    } else if(comp(s, "keye", 0) && comp(s, "nce", (int)s.size() - 3)) {
        cout << "YES";
    } else if(comp(s, "keyen", 0) && comp(s, "ce", (int)s.size() - 2)) {
        cout << "YES";
    } else if(comp(s, "keyenc", 0) && comp(s, "e", (int)s.size() - 1)) {
        cout << "YES";
    } else if(comp(s, "keyence", (int)s.size() - 7)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
    return 0;
}
#endif