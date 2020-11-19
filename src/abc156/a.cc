#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int r) {
    if(n >= 10) {
        return r;
    }
    return r + 100 * (10 - n);
}
/*
int main() {
    int n, r;
    cin >> n >> r;
    cout << solve(n, r);
}
*/