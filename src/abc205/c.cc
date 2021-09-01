#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    if(a == b) {
        cout << "=" << endl;
        return 0;
    }
    if(c % 2ll == 0ll) {
        if(abs(a) == abs(b)) {
            cout << "=" << endl;
        } else if(abs(a) < abs(b)) {
            cout << "<" << endl;
        } else {
            cout << ">" << endl;
        }
        return 0;
    }
    if(0 <= a && 0 <= b) {
        if(a < b) {
            cout << "<" << endl;
        } else {
            cout << ">" << endl;
        }
        return 0;
    }
    if(a < 0 && b < 0) {
        if(a < b) {
            cout << "<" << endl;
        } else { // a > b
            cout << ">" << endl;
        }
    }
    if(a >= 0 && b < 0) {
        cout << ">" << endl;
        return 0;
    } else {
        cout << "<" << endl;
        return 0;
    }

    return 0;
}
#endif