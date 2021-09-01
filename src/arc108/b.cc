#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int n, string s) {
    stack<char> stack;
    for(auto c : s) {
        stack.push(c);
        while(true) {
            if(stack.size() < 3)
                break;
            char x = stack.top();
            stack.pop();
            char o = stack.top();
            stack.pop();
            char f = stack.top();
            if(f == 'f' && o == 'o' && x == 'x')
                stack.pop();
            else {
                stack.push(o);
                stack.push(x);
                break;
            }
        }
    }
    return (int)stack.size();
}

#ifndef _debug
int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << solve(n, s) << endl;
}
#endif