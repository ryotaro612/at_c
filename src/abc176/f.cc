#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[2060][2020];
int ma[2020];

int solve(int n, vector<int> a) {
    for(int i = 0; i < 3 * n; i++) {
        a[i] = a[i] - 1;
    }

    int ret = 0;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            dp[x][y] = -1 << 20;
        }
        ma[x] = -1 << 20;
    }
    dp[a[0]][a[1]] = 0;
    ma[a[0]] = ma[a[1]] = 0;

    for(int i = 2; i + 2 < 3 * n; i += 3) {
        sort(a.begin() + i, a.begin() + i + 3);
        if(a[i] == a[i + 2]) {
            ret++;
            continue;
        }
        vector<vector<int>> cand;
        if(a[i] == a[i + 1]) {
            for(int x = 0; x < n; x++) {
                cand.push_back(
                    {a[i + 2], x, max(dp[a[i + 1]][x], dp[x][a[i + 1]]) + 1});
            }
        }
        if(a[i + 1] == a[i + 2]) {
            for(int x = 0; x < n; x++) {
                cand.push_back(
                    {a[i + 0], x, max(dp[a[i + 1]][x], dp[x][a[i + 1]]) + 1});
            }
        }
        for(int j = i; j < i + 3; j++) {
            for(int x = 0; x < n; x++) {
                cand.push_back({x, a[j], ma[x]});
            }
        }

        cand.push_back({a[i + 0], a[i + 1], dp[a[i + 2]][a[i + 2]] + 1});
        cand.push_back({a[i + 0], a[i + 2], dp[a[i + 1]][a[i + 1]] + 1});
        cand.push_back({a[i + 1], a[i + 2], dp[a[i + 0]][a[i + 0]] + 1});

        int tmp = -1;
        for(int x = 0; x < n; x++) {
            tmp = max(ma[x], tmp);
        }
        cand.push_back({a[i + 0], a[i + 1], tmp});
        cand.push_back({a[i + 0], a[i + 2], tmp});
        cand.push_back({a[i + 1], a[i + 2], tmp});

        for(auto c : cand) {
            dp[c[0]][c[1]] = max(dp[c[0]][c[1]], c[2]);
            ma[c[0]] = max(ma[c[0]], c[2]);
            ma[c[1]] = max(ma[c[1]], c[2]);
        }
    }

    int ma2 = 0;
    for(int x = 0; x < n; x++)
        ma2 = max(ma2, ma[x]);
    ma2 = max(ma2, dp[a[3 * n - 1]][a[3 * n - 1]] + 1);

    return ma2 + ret;
}
/*
int main() {
    int n;
    cin >> n;
    vector<int> a(3 * n);
    for(int i = 0; i < 3 * n; i++) {
        cin >> a[i];
    }

    cout << solve(n, a) << endl;
}
*/