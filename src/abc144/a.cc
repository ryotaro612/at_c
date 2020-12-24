#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int a, int b) {
    return a >= 1 && a <= 9 && b >= 1 && b <= 9 ? a * b : -1;
}
/*
int main() {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);
}
*/