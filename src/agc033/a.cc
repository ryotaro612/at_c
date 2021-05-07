#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int h, int w, vector<string> a) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        que;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(a[i][j] == '#')
                que.push(make_pair(0, make_pair(i, j)));
            /*
            if(a[i][j] == '.') {
                continue;
            }
            if(i > 0 && a[i - 1][j] == '.')
                que.push(make_pair(1, make_pair(i - 1, j)));
            if(j < w - 1 && a[i][j + 1] == '.')
                que.push(make_pair(1, make_pair(i, j + 1)));
            if(i < h - 1 && a[i + 1][j] == '.')
                que.push(make_pair(1, make_pair(i + 1, j)));
            if(j > 0 && a[i][j - 1] == '.')
                que.push(make_pair(1, make_pair(i, j - 1)));
                */
        }
    }
    int ans = 0;
    while(!que.empty()) {
        pair<int, pair<int, int>> item = que.top();
        que.pop();
        int i = item.second.first, j = item.second.second;
        bool used = false;
        if(i > 0 && a[i - 1][j] == '.') {
            used = true;
            a[i - 1][j] = '#';
            que.push(make_pair(item.first + 1, make_pair(i - 1, j)));
        }
        if(j < w - 1 && a[i][j + 1] == '.') {
            used = true;
            a[i][j + 1] = '#';
            que.push(make_pair(item.first + 1, make_pair(i, j + 1)));
        }
        if(i < h - 1 && a[i + 1][j] == '.') {
            used = true;
            a[i + 1][j] = '#';
            que.push(make_pair(item.first + 1, make_pair(i + 1, j)));
        }
        if(j > 0 && a[i][j - 1] == '.') {
            used = true;
            a[i][j - 1] = '#';
            que.push(make_pair(item.first + 1, make_pair(i, j - 1)));
        }
        if(used)
            ans = max(ans, item.first + 1);
    }

    return ans;
}

#ifndef _LOCAL
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for(int i = 0; i < h; i++)
        cin >> a[i];

    cout << solve(h, w, a) << endl;
    return 0;
}
#endif