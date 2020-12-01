#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int> p) {
    ll res = 0;

    for(int i = 0; i < n; i++) {
        if(i < n - 1 && p[i] == i + 1) {
            int temp = p[i];
            p[i] = p[i + 1];
            p[i + 1] = temp;
            res++;
        } else if(i == n - 1 && p[i] == n) {
            res++;
        }
    }
    return res;
}
/*
int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cout << solve(n, p);
}
*/