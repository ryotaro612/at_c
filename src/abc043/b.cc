#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(string s) {
    stack<char> stk;
    for(auto c : s) {
        if(c == 'B') {
            if(!stk.empty())
                stk.pop();
        } else
            stk.push(c);
    }
    string res;
    while(!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

#ifndef _LOCAL
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
}
#endif