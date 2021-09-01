#include <bits/stdc++.h>
using namespace std;
#ifndef _debug
int main() {
    int a, b;
    cin >> a >> b;
    cout << max(a + b, max(a - b, a * b)) << endl;
    return 0;
}
#endif