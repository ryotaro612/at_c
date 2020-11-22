#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, int> solve(string s, string t, int a, int b, string u) {
    if(u == s) {
        return make_pair(a - 1, b);
    }
    return make_pair(a, b - 1);
}
/*
int main() {
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;
    pair<int, int> res = solve(s, t, a, b, u);
    cout << res.first << " " << res.second;
}
*/