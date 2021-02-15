#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> a) {
    vector<int> acc(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        acc[i] = acc[i - 1] + a[i - 1];
    }
    if(acc[n] % n != 0) {
        return -1;
    }
    int per = acc[n] / n;
    int res = 0;
    for(int i = 0; i < n; i++) {
        int target = per * (i + 1);
        if(acc[i+1] != target) {
            res++;
        }
    }
    return res;
}
/*
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
}
*/