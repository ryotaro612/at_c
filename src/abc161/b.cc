#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int n, int m, vector<int> a) {
    //sort(a.begin(), a.end(), greater<int>());
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(4 * m * a[i] >= sum) {
            count++;
        }
    }
    return count >= m ? "Yes" : "No";
}
/*
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, m, a);
}
*/