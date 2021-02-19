#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int> a) {
    set<int> res;
    for(int i = 0; i < n; i++) {
        int aa = a[i];
        while(aa % 2 == 0)
            aa /= 2;

        res.insert(aa);
    }
    return (int)res.size();
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