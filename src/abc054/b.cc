#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int n, int m, vector<string> a, vector<string> b) {
    for(int i = 0; i + m - 1 < n; i++) {
        for(int j = 0; j + m - 1 < n; j++) {
            bool contains = true;
            for(int k = i; k < i + m; k++) {
                for(int l = j; l < j + m; l++) {
                    if(a[k][l] != b[k - i][l - j]) {
                        contains = false;
                    }
                }
            }
            if(contains)
                return "Yes";
        }
    }
    return "No";
}
/*
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    cout << solve(n, m, a, b) << endl;
}
*/