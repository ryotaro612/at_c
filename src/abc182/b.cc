#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int> a) {
    int res = 0;
    int ans;

    for(int i = 2; i <= 1000; i++) {
        int temp = 0;
        for(auto aa : a) {
            if(aa % i == 0)
                temp++;
        }
        if(temp >= res) {
            ans = i;
        }
        res = max(res, temp);
    }
    return ans;
}
/*
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a);
}
*/