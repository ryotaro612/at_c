#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
const ll MOD = 1000000007;

string solve(int a[]) { return (a[0] + a[1] + a[2]) > 21 ? "bust" : "win"; }
/*
int main() {
    int a[3];
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    cout << solve(a);
}
*/