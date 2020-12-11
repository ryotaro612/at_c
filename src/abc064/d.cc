#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int n, string s) {

    stack<char> stk;
    string res = "";
    for(auto ss : s) {
        if(ss == '(') {
            stk.push('(');
            res += "(";
        } else { // ss == ')'
            res += ")";
            if(stk.empty()) {
                res = "(" + res;
            } else {
                stk.pop();
            }
        }
    }
    while(!stk.empty()) {
        res += ")";
        stk.pop();
    }
    return res;
}
/*
int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << solve(n, s);
}
*/