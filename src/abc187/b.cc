#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int n, vector<int> x, vector<int> y) {
    int res = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(abs(y[j] - y[i]) <= abs(x[j] - x[i])) {
                //cout << i << " " << j << endl;
                res++;
            }
        }
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << solve(n, x, y) << endl;
    return 0;
}
#endif