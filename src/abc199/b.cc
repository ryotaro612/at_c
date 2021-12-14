#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int> a, vector<int> b) {
    int ans = 0;
    for(int i = 1; i <= 1000; i++) {
        bool ok = true;
        for(int j = 0; j < n; j++) {
            if(!(a[j] <= i && i <= b[j])) {
                ok = false;
                break;
            }
        }
        if(ok)
            ans++;
    }
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    cout << solve(n, a, b) << endl;
    return 0;
}
#endif