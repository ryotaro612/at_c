#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<vector<double>>>
    dp(101, vector<vector<double>>(101, vector<double>(101, 0.0)));
double f(int a, int b, int c) {
    if(dp[a][b][c] != 0)
        return dp[a][b][c];

    if(a == 100 || b == 100 || c == 100) {
        return 0;
    }
    double sum = (a + b + c);
    double res = ((double)(a / sum)) * (f(a + 1, b, c) + 1) +
                 ((double)(b / sum)) * (f(a, b + 1, c) + 1) +
                 ((double)(c / sum)) * (f(a, b, c + 1) + 1);
    dp[a][b][c] = res;
    return res;
}
double solve(int a, int b, int c) { return f(a, b, c); }
/*
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(15) << solve(a, b, c);
}
*/