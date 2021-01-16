#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int num_divisors(int a, vector<ll> cv) {
    int count = 0;
    for(auto c : cv) {
        if(a % c == 0)
            count++;
    }
    return count;
}

double solve(int n, vector<ll> cv) {
    double res = 0;
    for(auto c : cv) {
        int count = num_divisors(c, cv);
        if(count % 2 == 0) {
            res += 0.5;
        } else {
            double d_count = (double)count;
            res += (d_count + 1) / (2 * d_count);
        }
    }
    return res;
}
/*
int main() {
    int n;
    cin >> n;
    vector<ll> cv(n);
    for(int i = 0; i < n; i++) {
        cin >> cv[i];
    }
    cout << fixed << setprecision(10) << solve(n, cv) << endl;
    return 0;
}
*/