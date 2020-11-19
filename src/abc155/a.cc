#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int a, int b, int c) {
    if(a == b && a != c || a == c && a != b || b == c && c != a) {
        return "Yes";
    }
    return "No";
}
/*
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c);
}
*/