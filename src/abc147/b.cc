#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    string s;
    cin >> s;
    int res = 0;
    int n = (int)s.size();
    for(int i = 0; i < n / 2; i++) {
        if(s[i] != s[n - 1 - i])
            res++;
    }
    cout << res << endl;
    return 0;
}
#endif