#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int calc_area(int a, int b) { return 4 * a * b + 3 * a + 3 * b; }

int solve(int n, vector<int> &s) {
    unordered_set<int> areas;
    for(int a = 1; a <= 1000; a++) {
        for(int b = 1; b <= 1000; b++) {
            int area = calc_area(a, b);
            areas.insert(area);
        }
    }
    int res = 0;
    for(auto e : s) {
        if(areas.find(e) == areas.end())
            res++;
    }
    return res;
}
#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    cout << solve(n, s) << endl;
    return 0;
}
#endif