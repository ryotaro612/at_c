#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for(int i = 0; i < n; i++)
        cin >> w[i];
    vector<int> res;
    res.push_back(w[n - 1]);
    for(int i = n - 2; i >= 0; i--) {
        int res_n = (int)res.size();
        for(int j = 0; j < res_n; j++) {
            if(res[j] <= w[i]) {
                res[j] = w[i];
                break;
            }
            if(j == res_n - 1) {
                res.push_back(w[i]);
                break;
            }
        }
        sort(res.begin(), res.end(), greater<int>());
    }
    cout << res.size() << endl;
    return 0;
}
#endif