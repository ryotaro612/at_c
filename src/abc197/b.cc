#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int h, int w, int x, int y, vector<string> s) {
    int res = 1;
    for(int i = x - 2; i >= 0; i--) {
        if(s[i][y - 1] == '.')
            res++;
        else
            break;
    }
    for(int i = x; i < h; i++) {
        if(s[i][y - 1] == '.')
            res++;
        else
            break;
    }
    for(int i = y - 2; i >= 0; i--) {
        if(s[x - 1][i] == '.')
            res++;
        else
            break;
    }
    for(int i = y; i < w; i++) {
        if(s[x - 1][i] == '.')
            res++;
        else
            break;
    }

    return res;
}

#ifndef _debug
int main() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<string> s(h);
    for(int i = 0; i < h; i++)
        cin >> s[i];
    cout << solve(h, w, x, y, s) << endl;
    return 0;
}
#endif