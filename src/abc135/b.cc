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
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(i != p[i - 1])
            count++;
    }
    if(count <= 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
#endif