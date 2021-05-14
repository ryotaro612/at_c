#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
 
#ifndef _LOCAL
int main() {
    ll t, n, temp;
    cin >> t >> n;
 
    if((100ll * n) % t == 0ll) {
        temp = (100ll * n) / t - 1;
    } else {
        temp = (100ll * n) / t;
    }
    cout << temp + n << endl;
    return 0;
}
#endif