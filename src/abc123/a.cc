#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(vector<int> &a, int k) {
    for(int i = 0; i < 4; i++)
        for(int j = i + 1; j < 5; j++) {
            if(k < abs(a[i] - a[j]))
                return ":(";
        }
    return "Yay!";
}
#ifdef ONLINE_JUDGE
int main() {
    vector<int> a(5);
    rep(i, 5) cin >> a[i];
    int k;
    cin >> k;
    cout << solve(a, k) << endl;
    return 0;
}
#endif