#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    int a, b;
    cin >> a >> b;

    for(int c = 0; c <= 255; c++) {
        if((a ^ c) == b) {
            //cout << (a) << endl;
            //cout << (a ^ c) << endl;
            cout << c << endl;
            break;
        }
    }
    return 0;
}
#endif