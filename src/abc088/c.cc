#include <bits/stdc++.h>
using namespace std;
#ifndef _LOCAL
int main() {
    vector<vector<int>> c(3, vector<int>(3));
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> c[i][j];
    bool ok = true;

    vector<pair<int, int>> p = {make_pair(0, 1), make_pair(1, 2),
                                make_pair(0, 2)};
    for(auto e : p) {
        int x = c[e.first][0] - c[e.second][0];
        int y = c[e.first][1] - c[e.second][1];
        int z = c[e.first][2] - c[e.second][2];
        if(!(x == y && y == z))
            ok = false;
    }
    for(auto e : p) {
        int x = c[0][e.first] - c[0][e.second];
        int y = c[1][e.first] - c[1][e.second];
        int z = c[2][e.first] - c[2][e.second];
        if(!(x == y && y == z))
            ok = false;
    }
    if(ok)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;

    return 0;
}
#endif