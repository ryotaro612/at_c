#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n) {
    if(n % 2 == 0) {
        return n / 2;
    }
    return n / 2 + 1;
}
/*
int main() {
    int n;
    cin >> n;
    cout << solve(n);
}
*/