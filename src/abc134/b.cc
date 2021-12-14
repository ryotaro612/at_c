#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    int n, d;
    cin >> n >> d;

    int a = 2 * d + 1;

    if(n % a == 0)
        cout << n / a << endl;
    else
        cout << n / a + 1 << endl;

    return 0;
}
#endif