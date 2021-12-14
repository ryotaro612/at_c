#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<int> r(n), up(n, 0), down(n, 0);
    for(int i = 0; i < n; i++)
        cin >> r[i];
    up[n - 1] = down[n - 1] = 1;

    for(int i = n - 2; i >= 0; i--) {
        // up
        int a = -1;
        for(int j = i + 1; j < n; j++) {
            if(r[i] > r[j]) {
                if(a == -1 || down[a] < down[j])
                    a = j;
            }
        }
        if(a != -1)
            up[i] = down[a] + 1;
        // down
        a = -1;
        for(int j = i + 1; j < n; j++) {
            if(r[i] < r[j]) {
                if(a == -1 || up[a] < up[j])
                    a = j;
            }
        }
        if(a != -1)
            down[i] = up[a] + 1;
    }
    /*
    for(int i = 0; i < n; i++) {
        cout << up[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << down[i] << " ";
    }
    cout << endl;
    */
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(down[i] > 2)
            ans = max(ans, down[i]);
        if(up[i] > 2)
            ans = max(ans, up[i]);
    }
    // 3未満のときは0
    cout << ans << endl;
    return 0;
}
#endif
