#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    int a, b;
    cin >> a >> b;
    if(0 < a && b == 0) {
        cout << "Gold";
    } else if(a == 0 && 0 < b)
        cout << "Silver";
    else if(0 < a && 0 < b) {
        cout << "Alloy";
    }
    cout << endl;

    return 0;
}
#endif