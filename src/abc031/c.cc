#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const static int N_INF = -2000000;

int solve(int n, vector<int> a) {
    int res = N_INF;
    for(int ta = 0; ta < n; ta++) {
        int ao_best = N_INF, ta_best = N_INF;
        for(int ao = 0; ao < n; ao++) {
            if(ta == ao)
                continue;
            int p_ta = 0, p_ao = 0;
            for(int i = min(ta, ao); i <= max(ta, ao); i++) {
                if((i - min(ta, ao)) % 2 == 0)
                    p_ta += a[i];
                else
                    p_ao += a[i];
            }
            if(p_ao > ao_best) {
                ao_best = p_ao;
                ta_best = p_ta;
            }
        }
        res = max(res, ta_best);
    }
    return res;
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