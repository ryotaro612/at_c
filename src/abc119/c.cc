#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dfs(int index, int n, int a, int b, int c, int cost, int A, int B, int C,
        vector<int> &l) {
    if(index == n) {
        if(a == 0 || b == 0 || c == 0) {
            return 1 << 20;
        }
        return cost + abs(a - A) + abs(b - B) + abs(c - C);
    }
    int res0 = dfs(index + 1, n, a, b, c, cost, A, B, C, l);
    int res1 = dfs(index + 1, n, a + l[index], b, c, a == 0 ? cost : cost + 10,
                   A, B, C, l);
    int res2 = dfs(index + 1, n, a, b + l[index], c, b == 0 ? cost : cost + 10,
                   A, B, C, l);
    int res3 = dfs(index + 1, n, a, b, c + l[index], c == 0 ? cost : cost + 10,
                   A, B, C, l);
    return min(res0, min(res1, min(res2, res3)));
}

int solve(int n, int a, int b, int c, vector<int> l) {
    return dfs(0, n, 0, 0, 0, 0, a, b, c, l);
}
/*
int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> l(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }
    cout << solve(n, a, b, c, l);
}
*/