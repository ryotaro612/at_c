#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(string s) {
    int n = (int)s.size();
    ll ans = 0ll, c = 0ll;
    for(int i = 0; i < n;) {
        // cout << c << endl;
        if(i < n - 1 && s[i] == '2' && s[i + 1] == '5') {
            c++;
            i += 2;
        } else {
            i++;
            ans += (c * (c + 1ll)) / 2ll;
            c = 0;
        }
    }
    ans += (c * (c + 1ll)) / 2ll;
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;

    return 0;
}
#endif