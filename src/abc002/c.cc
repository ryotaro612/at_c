#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

#ifndef _LOCAL
int main() {
    ld xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    cout << fixed << setprecision(12)
         << abs(((xa - xc) * (yb - yc) - (xb - xc) * (ya - yc))) / (ld)2
         << endl;
    return 0;
}
#endif