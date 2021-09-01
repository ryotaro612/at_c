#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {

    int k, x;
    cin >> k >> x;

    for(int i = x - (k - 1); i < x + k; i++) {
        cout << i;
        if(i != x + k - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}
#endif