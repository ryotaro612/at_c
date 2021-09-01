#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int solve(int n, int r, string s) {
    int goal = n;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '.') {
            goal = max(0, i - r + 1);
            break;
        }
    }
    if(goal == n)
        return 0;

    int res = 0, pos = 0;
    while(pos < goal) {
        if(s[pos] == '.') {
            for(int i = pos; i < pos + r; i++)
                s[i] = 'o';
        } else
            pos++;
        res++;
    }
    return res + 1;
}

#ifndef _debug
int main() {
    int n, r;
    cin >> n >> r;
    string s;
    cin >> s;
    cout << solve(n, r, s) << endl;

    return 0;
}
#endif