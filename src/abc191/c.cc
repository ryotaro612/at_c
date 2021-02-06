#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int h, int w, vector<string> s) {
    int res = 0;
    for(int i = 0; i < h - 1; i++) {
        for(int j = 0; j < w - 1; j++) {
            int black = 0;
            if(s[i][j] == '#')
                black++;
            if(s[i][j + 1] == '#')
                black++;
            if(s[i + 1][j] == '#')
                black++;
            if(s[i + 1][j + 1] == '#')
                black++;
            if(black == 1 || black == 3) {
                res++;
            }
        }
    }
    return res;
}
/*
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++) {
        cin >> s[i];
    }
    cout << solve(h, w, s) << endl;
}
*/