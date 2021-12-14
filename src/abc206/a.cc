#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

#ifdef ONLINE_JUDGE
int main() {
    ld n;
    cin >> n;

    int a = floor(n * (ld)1.08);

    if(a < 206) {
        cout << "Yay!";
    } else if(a == 206) {
        cout << "so-so";
    } else {
        cout << ":(";
    }
    cout << endl;

    return 0;
}
#endif