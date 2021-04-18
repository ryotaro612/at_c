#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    int x, y;
    string W;
    cin >> x >> y >> W;
    --x;
    --y;
    string grid[9];
    for(int i = 0; i < 9; ++i) {
        cin >> grid[i];
    }
    int dx = 0, dy = 0;
    if(W.find('R') != string::npos) {
        dx = 1;
    } else if(W.find('L') != string::npos) {
        dx = -1;
    }
    if(W.find('U') != string::npos) {
        dy = -1;
    } else if(W.find('D') != string::npos) {
        dy = 1;
    }
    for(int i = 0; i < 4; ++i) {
        cout << grid[y][x];
        x += dx;
        y += dy;
        if(x < 0 || x >= 9) {
            dx = -dx;
            x += dx + dx;
        }
        if(y < 0 || y >= 9) {
            dy = -dy;
            y += dy + dy;
        }
    }
    cout << endl;
    return 0;
}
#endif