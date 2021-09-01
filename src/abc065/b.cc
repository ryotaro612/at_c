#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int n, vector<int> a) {
    vector<bool> used(n, false);
    int count = 0;
    int index = 0;
    while(!used[index]) {
        used[index] = true;
        index = a[index] - 1;
        count++;
        if(index == 1)
            return count;
    }

    return -1;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
}
#endif