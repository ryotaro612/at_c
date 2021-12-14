#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
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