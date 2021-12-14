#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    vector<vector<int>> ans(h, vector<int>(w, 0));
    for(int i = 0; i < b; i++)
        for(int j = 0; j < a; j++)
            ans[i][j] = 1;
    for(int i = b; i < h; i++)
        for(int j = a; j < w; j++)
            ans[i][j] = 1;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
#endif