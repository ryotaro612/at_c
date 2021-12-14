#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll cond = c * d - b;
    if(cond <= 0) {
        cout << "-1" << endl;
        return 0;
    }

    for(int i = 0;; i++) {
        if(a <= i * cond) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
#endif