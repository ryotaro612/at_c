#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve_maximal_value(int n, vector<int> b) {
    int acc = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            acc += b[0];
            continue;
        }
        if(i == n - 1) {
            acc += b[i - 1];
            break;
        }
        acc += std::min(b[i], b[i - 1]);
    }
    return acc;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for(int i = 0; i < n - 1; i++)
        cin >> b[i];
    cout << solve_maximal_value(n, b) << endl;
    return 0;
}
#endif
