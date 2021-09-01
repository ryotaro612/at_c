#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int sx, int sy, int tx, int ty) {
    int x = sx, y = sy;
    string s;
    while(x != tx) {
        x++;
        s.push_back('R');
    }
    while(y != ty) {
        y++;
        s.push_back('U');
    }
    while(x != sx) {
        x--;
        s.push_back('L');
    }
    while(y != sy) {
        y--;
        s.push_back('D');
    }
    y--;
    s.push_back('D');
    while(x != tx + 1) {
        x++;
        s.push_back('R');
    }
    while(y != ty) {
        y++;
        s.push_back('U');
    }
    x--;
    s.push_back('L');
    y++;
    s.push_back('U');
    while(x != sx - 1) {
        x--;
        s.push_back('L');
    }
    while(y != sy) {
        y--;
        s.push_back('D');
    }
    x++;
    s.push_back('R');

    return s;
}

#ifndef _debug
int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    cout << solve(sx, sy, tx, ty) << endl;
    return 0;
}
#endif