#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int v, int t, int s, int d) {
    int from = v * t, to = v * s;
    if(d >= from && to >= d) {
        return "No";
    }
    return "Yes";
}
/*
int main() {
    int v, t, s, d;
    cin >> v >> t >> s >> d;
    cout << solve(v, t, s, d) << endl;
    return 0;
}
*/