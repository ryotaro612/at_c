#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];

    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        vector<int> a(3);
        a[0] = p[i - 1];
        a[1] = p[i];
        a[2] = p[i + 1];
        sort(a.begin(), a.end());
        if(p[i] == a[1])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
#endif