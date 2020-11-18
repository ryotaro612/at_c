#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int m) {
    int res = 0;
    if(n > 1) {
        res += (n * (n - 1)) / 2;
    }
    if(m > 1) {
        res += (m * (m - 1)) / 2;
    }
    return res;
}
/*
int main() {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m);
}
*/