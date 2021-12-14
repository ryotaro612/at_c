#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dfs(ll n, string s) {
    if((int)s.size() > 0 && stoll(s) > n)
        return 0ll;
    bool three = false, five = false, seven = false;
    ll rest = 0ll;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '3')
            three = true;
        else if(s[i] == '5')
            five = true;
        else if(s[i] == '7')
            seven = true;
    }
    if(three && five && seven)
        rest = 1ll;
    rest += dfs(n, s + '3');
    rest += dfs(n, s + '5');
    rest += dfs(n, s + '7');
    return rest;
}

ll solve(string s) {
    ll n = stoll(s);
    return dfs(n, "");
}

#ifdef ONLINE_JUDGE
int main() {
    string n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif