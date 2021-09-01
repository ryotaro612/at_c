#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> solve(int h, int w, int k, vector<string> s) {
    vector<pair<int, int>> straw;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(s[i][j] == '#')
                straw.push_back(make_pair(i, j));
        }
    }
    sort(straw.begin(), straw.end(), [](pair<int, int> a, pair<int, int> b) {
        if(a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    });

    vector<vector<int>> ans(h, vector<int>(w, 0));
    int ichigo = 1;
    for(int i = 0; i < (int)straw.size(); i++) {
        for(int k = straw[i].first; 0 <= k; k--) {
            for(int l = straw[i].second; 0 <= l; l--) {
                if(ans[k][l] == 0) {
                    ans[k][l] = ichigo;
                } else {
                    break;
                }
            }
        }
        if(i == (int)straw.size() - 1 || straw[i].first < straw[i + 1].first) {
            for(int j = straw[i].first; 0 <= j && ans[j][w - 1] == 0; j--) {
                int ichi = ans[j][0];
                for(int k = 1; k < w; k++) {
                    if(ans[j][k] == 0) {
                        ans[j][k] = ichi;
                    } else
                        ichi = ans[j][k];
                }
            }
        }
        ichigo++;
    }
    for(int j = 0; j < w; j++) {
        int ichi = ans[0][j];
        for(int i = 1; i < h; i++) {
            if(ans[i][j] == 0)
                ans[i][j] = ichi;
            else
                ichi = ans[i][j];
        }
    }
    return ans;
}

#ifndef _debug
int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for(int i = 0; i < h; i++)
        cin >> s[i];
    vector<vector<int>> ans = solve(h, w, k, s);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << ans[i][j];
            if(j == w - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    return 0;
}
#endif