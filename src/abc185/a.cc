#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<int> a) {
    int res = 1000;
    for(int i = 0; i < 4; i++) {
        res = min(res, a[i]);
    }
    return res;
}
/*
int main() {
    vector<int> a(4);
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    cout << solve(a);
}
*/