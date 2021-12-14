#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
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