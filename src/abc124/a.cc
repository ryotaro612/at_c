#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b) {
    vector<int> ans = {a + a - 1, b + a, b + b - 1};
    return *max_element(ans.begin(), ans.end());
}

#ifdef ONLINE_JUDGE
int main() {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}
#endif