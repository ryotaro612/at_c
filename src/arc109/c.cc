#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

char solve(int n, int k, string s) {
    s = s + s;
    while(k-- > 0) {
        n = (int)s.size();
        string temp;
        for(int i = 0; i < n; i += 2) {
            char a = s[i], b = s[i + 1];
            if(a == b) {
                temp.push_back(a);
            } else if(a == 'R') {
                if(b == 'P') {
                    temp.push_back(b);
                } else { // S
                    temp.push_back(a);
                }
            } else if(a == 'P') {
                if(b == 'R') {
                    temp.push_back(a);
                } else { // S
                    temp.push_back(b);
                }
            } else { // a == 'S'
                if(b == 'R') {
                    temp.push_back(b);
                } else { // b == 'P'
                    temp.push_back(a);
                }
            }
        }
        s = temp;
        s = s + s;
    }
    return s[0];
}

#ifndef _debug
int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << solve(n, k, s) << endl;
    return 0;
}
#endif