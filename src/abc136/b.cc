#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(((int)to_string(i).size()) % 2 == 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
#endif