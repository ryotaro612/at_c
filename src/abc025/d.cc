#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const static ll MOD = 10e9 + 7;

int num_bit(ll current) {
    int count = 0;
    while(current > 0) {
        if(current & 1) {
            count++;
        }
        current = current >> 1;
    }
    return count;
}

int bit_get(int value, int idx) { return (value & (1 << idx)) > 0 ? 1 : 0; }

bool placeable(ll current, int idx, int current_mx, vector<int> &pos,
               vector<vector<int>> &x) {
    if(pos[current_mx] != -1 && pos[current_mx] != idx)
        return false;
    if(x[idx / 5][idx % 5] != 0 && x[idx / 5][idx % 5] != current_mx + 1) {
        return false;
    }
    if(idx % 5 != 0 && idx % 5 != 4) {
        int c = 0;
        if(bit_get(current, idx - 1))
            c++;
        if(bit_get(current, idx + 1))
            c++;
        if(c == 1)
            return false;
    }
    if(idx / 5 != 0 && idx / 5 != 4) {
        int c = 0;
        if(bit_get(current, idx - 5))
            c++;
        if(bit_get(current, idx + 5))
            c++;
        if(c == 1)
            return false;
    }
    return true;
}

ll solve(vector<vector<int>> x) {
    vector<int> pos(25, -1);
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(x[i][j] > 0) {
                pos[x[i][j] - 1] = i * 5 + j;
            }
        }
    }
    vector<ll> dp(1 << 25, 0);
    dp[0] = 1;
    for(ll i = 0; i < (1 << 25) - 1; i++) {
        if(dp[i] == 0)
            continue;
        int num_numbers = num_bit(i);

        for(int j = 0; j < 25; j++) {
            if(bit_get(i, j) > 0)
                continue;
            if(placeable(i, j, num_numbers, pos, x)) {
                dp[i | (1 << j)] = (dp[i] + dp[i | (1 << j)]) % MOD;
                //cout << (i | (1 << j)) << " -> " << dp[i | (1 << j)] << endl;
            }
        }
    }
    return dp[(1 << 25) - 1];
}

int main() {
    vector<vector<int>> x(5, vector<int>(5, 0));
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> x[i][j];
        }
    }

    cout << solve(x) << endl;
}