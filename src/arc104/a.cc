#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

pair<int, int> solve(int a, int b) {
    return make_pair((a + b) / 2, (a - b) / 2);
}

#ifndef _LOCAL
int main() {
    int a, b;
    cin >> a >> b;
    pair<int, int> res = solve(a, b);
    cout << res.first << " " << res.second << endl;
}
#endif