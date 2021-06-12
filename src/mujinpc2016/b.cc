#include <bits/stdc++.h>
typedef long double ld;
using namespace std;

#ifndef _LOCAL
int main() {
    ld pi = acos(-1), oa, ab, bc;
    cin >> oa >> ab >> bc;

    ld big = (ab + bc + oa) * (ab + bc + oa) * pi;
    cout << fixed << setprecision(12);
    if(ab + bc < oa) {
        ld d = oa - ab - bc;
        cout << big - d * d * pi;
    } else if(oa + ab < bc) {
        ld d = bc - oa - ab;
        cout << big - d * d * pi;
    } else if(oa + bc < ab) {
        ld d = ab - oa - bc;
        cout << big - d * d * pi;
    } else {
        cout << big;
    }
    cout << endl;
    return 0;
}
#endif