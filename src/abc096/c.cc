#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++)
        cin >> s[i];

    for(int i = 0; i < h; i++) {
        for(int j = j = 0; j < w; j++) {
            if(s[i][j] == '.')
                continue;
            if(i > 0 && s[i - 1][j] == '#')
                continue;
            if(j < w - 1 && s[i][j + 1] == '#')
                continue;
            if(i < h - 1 && s[i + 1][j] == '#')
                continue;
            if(j > 0 && s[i][j - 1] == '#')
                continue;
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}