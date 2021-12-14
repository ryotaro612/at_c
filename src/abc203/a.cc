#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b) {
        cout << c << endl;
        return 0;
    }
    if(b == c) {
        cout << a << endl;
        return 0;
    }
    if(a == c) {
        cout << b << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}
#endif