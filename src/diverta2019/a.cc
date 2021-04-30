#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<string> s) {
    queue<int> a, b, ba, o;
    for(int i = 0; i < n; i++) {
        if(s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A')
            ba.push(i);
        else if(s[i][s[i].size() - 1] == 'A')
            a.push(i);
        else if(s[i][0] == 'B')
            b.push(i);
        else
            o.push(i);
    }
    string c;
    // cout << a.size() << " " << b.size() << " " << ba.size() << " " <<
    // o.size() << endl;
    while(!ba.empty()) {
        c += s[ba.front()];
        ba.pop();
    }

    if(!a.empty()) {
        c = s[a.front()] + c;
        a.pop();
    }
    while(!(a.empty() && b.empty() && o.empty())) {
        if(c[c.size() - 1] == 'A') {
            if(!b.empty()) {
                c += s[b.front()];
                b.pop();
            } else if(!o.empty()) {
                c += s[o.front()];
                o.pop();
            } else {
                c += s[a.front()];
                a.pop();
            }
        } else {
            if(!a.empty()) {
                c += s[a.front()];
                a.pop();
            } else if(!o.empty()) {
                c += s[o.front()];
                o.pop();
            } else {
                c += s[b.front()];
                b.pop();
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < (int)c.size() - 1; i++) {
        if(c[i] == 'A' && c[i + 1] == 'B')
            ans++;
    }
    // cout << c << endl;
    return ans;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];

    cout << solve(n, s) << endl;
    return 0;
}
#endif