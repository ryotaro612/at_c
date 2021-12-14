#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    string ans = "";
    while(n > 0) {
        if(n % 2ll == 0) {
            n /= 2ll;
            ans.push_back('B');
        } else {
            n -= 1ll;
            ans.push_back('A');
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
#endif