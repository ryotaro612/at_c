#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = a; i <= b; i++) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
#endif