#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    int x, a;
    cin >> x >> a;
    int ans;
    if(x < a)
        ans = 0;
    else
        ans = 10;
    cout << ans << endl;

    return 0;
}
#endif