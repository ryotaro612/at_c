#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    for(int i = 0; i + 2 < n; i++)
        if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
            res++;
    cout << res << endl;
}
#endif