#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    string s, ans;
    cin >> s;

    if(s[0] == s[1] || s[1] == s[2] || s[2] == s[3]) {
        ans = "Bad";
    } else {
        ans = "Good";
    }
    cout << ans << endl;
    return 0;
}
#endif