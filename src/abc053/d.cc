#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int> a) {

    set<int> b;
    for(auto aa : a)
        b.insert(aa);

    int size = (int)b.size();

    return size % 2 == 0 ? size - 1 : size;
}
/*
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
}
*/