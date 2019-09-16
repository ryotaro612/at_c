#include <algorithm>
#include "maximal_value.h"

/*
https://atcoder.jp/contests/abc140/tasks/abc140_c
*/
int solve_maximal_value(int n, int b[]) {
    int acc = 0;
    for(int i = 0;i<n;i++) {
        if(i == 0) {
            acc += b[0];
            continue;
        }
        if(i == n - 1) {
            acc += b[i-1];
            break;
        }
        acc += std::min(b[i], b[i-1]);
    }
    return acc;
}
