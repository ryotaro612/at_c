#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {

    ll m;
    cin >> m;
    if(m < 100)
        cout << "00" << endl;
    else if(m >= 100 && m <= 5000) {
        if(m < 1000) {
            m /= 100;
            cout << "0" << m << endl;
        } else {
            m /= 100;
            cout << m << endl;
        }
    } else if(m >= 6000 && m <= 30000) {
        m /= 1000;
        m += 50;
        cout << m << endl;
    } else if(m >= 35000 && m <= 70000) {
        m /= 1000;
        m -= 30;
        m /= 5;
        m += 80;
        cout << m << endl;
    } else {
        cout << 89 << endl;
    }

    return 0;
}
#endif