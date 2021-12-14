#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s) {
    if("atcoder" < s)
        return 0;
    int n = s.size();
    bool ok = false;
    int i;
    for(i = 0; i < n; i++) {
        if(s[i] != 'a') {
            ok = true;
            break;
        }
    }
    if(!ok)
        return -1;
    // atcoder >= s && a以外がある && a s[1] s[2] ... && 答えは1以上
    if(s[1] != 'a') {
        return 1;
    }

    // a a s[2] s[3] ..
    if(s[i] > 't')
        return i - 1;
    return i;
    /*

    if(s[2] != 'a') {
        if(s[2] <= 't')
            return 2;
        return 1;
    }
    // a a a s[3] ..
    */
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(auto ss : s)
        cout << solve(ss) << endl;
    return 0;
}
#endif