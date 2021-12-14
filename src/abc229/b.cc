#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(ll a, ll b) {
    string s_a = to_string(a);
    string s_b = to_string(b);
    reverse(s_a.begin(), s_a.end());
    reverse(s_b.begin(), s_b.end());
    rep(i, (int)min(s_a.size(), s_b.size())) {
        int d_a = s_a[i] - '0';
        int d_b = s_b[i] - '0';
        if(d_a + d_b >= 10)
            return "Hard";
    }
    return "Easy";
}

#ifdef ONLINE_JUDGE
int main() {
    ll a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}
#endif