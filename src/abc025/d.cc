#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const static ll MOD = 10e9 + 7;

int num_bit(ll current) {
    int count = 0;
    while(current > 0) {
        current = current >> 1;
        count++;
    }
    return count;
}

vector<vector<bool>> revert(ll current) {
    vector<vector<bool>> x(25, vector<bool>(25, false));
    for(int i = 0; i < 25; i++) {
        if(current & (1 << i)) {
            x[i / 5][i % 5] = true;
        }
    }
    return x;
}
/**
 * one origin
 */
pair<int, int> revert_point(int idx) {
    return make_pair((idx - 1) / 5, (idx - 1) % 5);
}

bool placeable(int idx_to_place, ll current, vector<int> used_map) {
    int number = calc_number_to_place(current);
    if(used_map[number] != -1 && used_map[number] != idx_to_place) {
        return false;
    }
    // TODO
    vector<vector<bool>> x = revert(current);
    pair<int, int> point = revert_point(idx_to_place);
    bool result = true;
    if(1 <= point.first && point.first <= 3) {
        if(x[point.first - 1][point.second] &&
           !x[point.first + 1][point.second]) {
            result = false;
        }
        if(!x[point.first - 1][point.second] &&
           x[point.first + 1][point.second]) {
            result = false;
        }
    }
    return result;
}
/**
 * 1オリジンでnumber
 */
vector<int> calc_used_map(vector<vector<int>> &x) {
    vector<int> mp(26, -1);
    for(int i = 0; i < 25; i++) {
        int number = x[i / 5][i % 5];
        if(number == 0) {
            continue;
        }
        mp[number] = i + 1;
    }
    return mp;
}

ll solve(vector<vector<int>> x) {
    vector<ll> dp(1 << 25, 0);
    dp[0] = 1;
    // XXX
    vector<int> used_map = calc_used_map(x);

    for(ll i = 0; i < (1 << 25) - 1; i++) {
        for(int j = 0; j < 25; j++) {
            if(dp[i] == 0) {
                continue;
            }
            ll current = i - pow(2, j - 1);
            if(current < 0) { // iにはできない
                continue;
            }
            // 使われている
            if(dp[i] > 0 && placeable(j, current, used_map)) {
                dp[i] = (dp[i] + dp[current]) % MOD;
            }
        }
    }
    return dp[(1 << 25) - 1];
}
/*
int main() {
    vector<vector<int>> x(5, vector<int>(5, 0));
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> x[i][j];
        }
    }

    cout << solve(x) << endl;
}
*/