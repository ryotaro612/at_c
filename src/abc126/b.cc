#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_mm(string s) {
    if(s[0] == '0') {
        if(s[1] != '0')
            return true;
        else
            return false;
    } else if(s[0] == '1') {
        if(s[1] - '0' <= 2)
            return true;
        else
            return false;
    }
    return false;
}

#ifndef _debug
int main() {
    string s;
    cin >> s;

    string a = s.substr(0, 2), b = s.substr(2, 4);

    if(is_mm(a)) {
        if(is_mm(b)) {
            cout << "AMBIGUOUS" << endl;
        } else {
            cout << "MMYY" << endl;
        }
    } else {
        if(is_mm(b)) {
            cout << "YYMM" << endl;
        } else {
            cout << "NA" << endl;
        }
    }

    return 0;
}
#endif