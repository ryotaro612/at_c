#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
    int x;
    cin >> x;
    if(x < 40) {
        cout << 40 - x << endl;
    } else if(x < 70) {
        cout << 70 - x << endl;
    } else if(x < 90) {
        cout << 90 - x << endl;
    } else
        cout << "expert" << endl;
    return 0;
}
#endif