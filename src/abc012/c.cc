#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifndef _debug
int main() {
    int n, sum = 0;
    cin >> n;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++)
            sum += i * j;
    }
    int mul = sum - n;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            if(mul == i * j) {
                cout << i << " x " << j << endl;
            }
        }
    }

    return 0;
}
#endif