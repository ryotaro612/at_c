#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i = 0; i < n; i++)
        cin >> d[i];
    int res = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++)
            res += d[i] * d[j];
    }
    cout << res << endl;
    return 0;
}
#endif