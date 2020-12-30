#include <bitset>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int x[5][5];
int iniPlaceI[30], iniPlaceJ[30];

static int dp[(1 << 25) + 10];

inline int toInd(int i, int j) { return i * 5 + j; }

bool check(int bit, int nextNum, int i, int j) {
    // left-right check
    int li = i, lj = j - 1;
    int ri = i, rj = j + 1;
    if(lj >= 0 && rj < 5) {
        int leftBit = ((bit & (1 << toInd(li, lj))) != 0);
        int rightBit = ((bit & (1 << toInd(ri, rj))) != 0);
        if(leftBit + rightBit == 1)
            return false;
    }

    // ue-shita check
    int ui = i - 1, uj = j;
    int si = i + 1, sj = j;
    if(ui >= 0 && si < 5) {
        int ueBit = ((bit & (1 << toInd(ui, uj))) != 0);
        int shitaBit = ((bit & (1 << toInd(si, sj))) != 0);
        if(ueBit + shitaBit == 1)
            return false;
    }

    return true;
}

int solve(vector<vector<int>> x) {
    memset(iniPlaceI, -1, sizeof(iniPlaceI));
    memset(iniPlaceJ, -1, sizeof(iniPlaceJ));
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j) {
            if(x[i][j] != 0) {
                iniPlaceI[x[i][j]] = i;
                iniPlaceJ[x[i][j]] = j;
            }
        }

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int bit = 0; bit < (1 << 25); ++bit) {
        if(dp[bit] == 0)
            continue;
        int nextNum = __builtin_popcount(bit) + 1;

        // if (dp[bit]) cout << bitset<25>(bit) << ": " << dp[bit] << endl;

        if(iniPlaceI[nextNum] != -1) {
            if(bit & (1 << toInd(iniPlaceI[nextNum], iniPlaceJ[nextNum])))
                continue;
            if(check(bit, nextNum, iniPlaceI[nextNum], iniPlaceJ[nextNum])) {
                int nextBit =
                    bit | (1 << toInd(iniPlaceI[nextNum], iniPlaceJ[nextNum]));
                dp[nextBit] += dp[bit];
                if(dp[nextBit] >= MOD)
                    dp[nextBit] -= MOD;
            }
        } else {
            for(int i = 0; i < 5; ++i) {
                for(int j = 0; j < 5; ++j) {
                    if(bit & (1 << toInd(i, j)))
                        continue;
                    if(check(bit, nextNum, i, j)) {
                        int nextBit = bit | (1 << toInd(i, j));
                        dp[nextBit] += dp[bit];
                        if(dp[nextBit] >= MOD)
                            dp[nextBit] -= MOD;
                    }
                }
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