#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
    vector<string> s(3);
    rep(i, 3) cin >> s[i];
    string t, ans = "";
    cin >> t;
    for(auto c : t) {
        int index = (c - '0') - 1;
        ans += s[index];
    }
    cout << ans << endl;
    return 0;
}
#endif