#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    // what if N =1?
    queue<int> que;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1')
            que.push(i);
    }
    ll ans = 0ll;
    for(int i = 0; i < n; i++) {
        if(s[i] == t[i]) {
            if(t[i] == '1') {
                assert(i == que.front());
                que.pop();
            }
            continue;
        }
        if(t[i] == '0') { // s[i] == 1
            assert(que.front() == i);
            que.pop();
            if(que.size() == 0) {
                cout << "-1" << endl;
                return 0;
            }
            s[que.front()] = '0';
            ans += que.front() - i;
            que.pop();
        } else { // t[i] == '1' && s[i] == '0'
            if(que.size() == 0) {
                cout << "-1" << endl;
                return 0;
            }
            s[que.front()] = '0';
            ans += que.front() - i;
            que.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
#endif