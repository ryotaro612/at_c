#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int c, vector<int> &a) {
    int res = numeric_limits<int>::max();

    for(int i = 0; i < (1 << 10); i++) {
        vector<int> pos;
        for(int j = 0; j < 10; j++) {
            if(i & (1 << j))
                pos.push_back(j);
        }
        if((int)pos.size() != 2)
            continue;

        int cost1 = 0;
        for(int j = 0; j < n; j += 2) {
            if(a[j] != pos[0] + 1)
                cost1 += c;
            if(j + 1 < n && a[j + 1] != pos[1] + 1)
                cost1 += c;
        }
        int cost2 = 0;
        for(int j = 0; j < n; j += 2) {
            if(a[j] != pos[1] + 1)
                cost2 += c;
            if(j + 1 < n && a[j + 1] != pos[0] + 1)
                cost2 += c;
        }
        res = min(res, min(cost1, cost2));
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, c, a) << endl;
    return 0;
}
#endif
