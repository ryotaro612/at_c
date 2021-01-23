#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dfs(bool y, int index, int n, vector<string> &s) {
    if(index == n) {
        return y ? 1 : 0;
    }
    if(s[index] == "AND") {
        if(y) {
            return dfs(y, index + 1, n, s) + dfs(false, index + 1, n, s);
        } else {
            return 2 * dfs(false, index + 1, n, s);
        }
    }
    // s[index] == or
    if(y) {
        return 2 * dfs(true, index + 1, n, s);
    } else {
        return dfs(true, index + 1, n, s) + dfs(y, index + 1, n, s);
    }
}

ll solve(int n, vector<string> s) {
    return dfs(true, 0, n, s) + dfs(false, 0, n, s);
}

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    cout << solve(n, s) << endl;
}