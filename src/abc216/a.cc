#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _debug
int main() {
    string xy;
    cin >> xy;

    string x = xy.substr(0, xy.size() - 2);
    int y = xy[xy.size() - 1] - '0';
    if(y <= 2) {
        cout << x << "-" << endl;
    } else if(y <= 6) {
        cout << x << endl;
    } else {
        cout << x << "+" << endl;
    }
    return 0;
}
#endif