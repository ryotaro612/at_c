#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(vector<vector<int>> a, int n, vector<int> b) {
    vector<vector<bool>> bingo(3, vector<bool>(3, false));
    for(auto bb : b) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(a[i][j] == bb)
                    bingo[i][j] = true;
            }
        }
    }
    for(int i = 0; i < 3; i++) {
        bool ok = true;
        for(int j = 0; j < 3; j++) {
            if(!bingo[i][j])
                ok = false;
        }
        if(ok)
            return "Yes";
    }
    for(int i = 0; i < 3; i++) {
        bool ok = true;
        for(int j = 0; j < 3; j++) {
            if(!bingo[j][i])
                ok = false;
        }
        if(ok)
            return "Yes";
    }
    if(bingo[0][0] && bingo[1][1] && bingo[2][2])
        return "Yes";
    if(bingo[0][2] && bingo[1][1] && bingo[2][0])
        return "Yes";
    return "No";
}

#ifndef _LOCAL
int main() {
    vector<vector<int>> a(3, vector<int>(3));
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> a[i][j];
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++)
        cin >> b[i];
    cout << solve(a, n, b) << endl;
}
#endif