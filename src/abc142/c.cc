#include <bits/stdc++.h>
using namespace std;
#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[i] = make_pair(temp, i);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        cout << a[i].second + 1;
        if(i == n - 1)
            cout << endl;
        else
            cout << " ";
    }

    return 0;
}
#endif