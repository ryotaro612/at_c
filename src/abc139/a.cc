#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for(int i = 0; i < 3; i++)
        if(s[i] == t[i])
            ans++;
    cout << ans << endl;
    return 0;
}
#endif