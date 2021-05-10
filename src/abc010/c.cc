#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

#ifndef _LOCAL
int main() {
    int n;
    ld txa, tya, txb, tyb, t, v;
    cin >> txa >> tya >> txb >> tyb >> t >> v >> n;
    vector<ld> x(n), y(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    string s = "NO";
    // ld d = sqrt((txa - txb) * (txa - txb) + (tya - tyb) * (tya - tyb));
    for(int i = 0; i < n; i++) {
        ld a = (txa - x[i]) * (txa - x[i]) + (tya - y[i]) * (tya - y[i]);
        ld b = (txb - x[i]) * (txb - x[i]) + (tyb - y[i]) * (tyb - y[i]);
        //cout << a << " " << b << " " << sqrt(a) + sqrt(b) << endl;
        if(sqrt(a) + sqrt(b) <= t * v) {
            s = "YES";
            break;
        }
    }
    cout << s << endl;
    return 0;
}
#endif