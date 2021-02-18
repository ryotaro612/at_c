#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int m) {
    for(int old = 0; old <= n; old++) {
        int num_feet = m - old * 3, num_people = n - old;
        if(num_feet % 2 == 0) {
            int baby = num_feet / 2 - num_people;
            if(baby >= 0 && n >= baby) {
                int man = n - old - baby; 
                if(man >= 0 && n >= man) {
                return {man, old, baby};
                }
            }
        }
    }
    return {-1, -1, -1};
}
/*
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> res = solve(n, m);
    cout << res[0] << " " << res[1] << " " << res[2] << endl;
}
*/