#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve2(string s) {
    string cache = "", t = "";
    bool flip = false;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == 'R' || i == ((int)s.size() - 1)) {
            if(i == ((int)s.size() - 1) && s[i] != 'R')
                cache.push_back(s[i]);
            if(cache != "") {
                if(!flip) {
                    t += cache;
                } else {
                    reverse(cache.begin(), cache.end());
                    cache += t;
                    t = cache;
                }
                cache = "";
            }
            if(s[i] == 'R')
                flip = !flip;
        } else {
            cache.push_back(s[i]);
        }
    }
    if(flip)
        reverse(t.begin(), t.end());
    stack<char> a;
    for(int i = 0; i < (int)t.size(); i++) {
        if(a.empty()) {
            a.push(t[i]);
        } else if(a.top() == t[i]) {
            a.pop();
        } else {
            a.push(t[i]);
        }
    }
    string ans = "";
    while(!a.empty()) {
        ans += a.top();
        a.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string solve(string s) {
    bool flip = false;
    string t = "";
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == 'R') {
            flip = !flip;
            continue;
        }
        if(!flip) {
            t.push_back(s[i]);
        } else {
            string temp = string(1, s[i]);
            temp += t;
            t = temp;
        }
    }
    if(flip)
        reverse(t.begin(), t.end());
    stack<char> a;
    // cout << t << endl;
    for(int i = 0; i < (int)t.size(); i++) {
        if(a.empty()) {
            a.push(t[i]);
        } else if(a.top() == t[i]) {
            a.pop();
        } else {
            a.push(t[i]);
        }
    }
    string ans = "";
    while(!a.empty()) {
        ans += a.top();
        a.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

#ifndef _LOCAL
int main() {
    string s;
    cin >> s;
    cout << solve2(s) << endl;
    return 0;
}
#endif