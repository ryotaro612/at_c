#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int a, int b) {
    if(a == 1 && b == 2) {
        return 3;
    }
    if(a == 2 && b == 1) {
        return 3;
    }
    if(a == 2 && b == 3) {
        return 1;
    }
    if(a == 3 && b == 2) {
        return 1;
    }
    return 2;
}
/*
int main() {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);
}
*/