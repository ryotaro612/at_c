#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n, step = 0;
    string s, a = "b";
    cin >> n >> s;
    while(true) {
        if((int)a.size() > (int)s.size())
            break;
        if(s == a) {
            cout << step << endl;
            return 0;
        }
        a = "a" + a + "c";
        step++;
        if(s == a) {
            cout << step << endl;
            return 0;
        }
        a = "c" + a + "a";
        step++;
        if(s == a) {
            cout << step << endl;
            return 0;
        }
        a = "b" + a + "b";
        step++;
    }
    cout << "-1" << endl;
    return 0;
}
#endif