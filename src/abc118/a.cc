#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    int a, b;
    cin >> a >> b;

    if(b % a)
        cout << b - a;
    else
        cout << a + b;
    cout << endl;
    return 0;
}
#endif