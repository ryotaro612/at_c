#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(int x, int y, int z) {
    int xx = y, yy = x;
    return {z, yy, xx};
}
/*
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    for(auto a : solve(x, y, z)) {
        cout << a << " ";
    }
}
*/