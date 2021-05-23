#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    string s;
    cin >> s;
    string ans = s;
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < (int)ans.size(); i++) {
        if(ans[i] == '6') {
            ans[i] = '9';
        } else if(ans[i] == '9') {
            ans[i] = '6';
        }
    }
    cout << ans << endl;
    return 0;
}
#endif