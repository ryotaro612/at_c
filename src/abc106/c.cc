#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;

    ll p1 = -1ll;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '1')
            p1 = i;
        else
            break;
    }
    if(k <= p1 + 1ll) {
        cout << 1 << endl;
        return 0;
    }
    cout << s[p1 + 1] << endl;
    return 0;
}

#endif
// 5000000000000000
//
