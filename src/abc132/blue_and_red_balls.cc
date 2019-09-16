#include<vector>
#include<iostream>
#include<array>

std::vector<int> solve_blue_and_red_balls(int n, int k) {
    int max_n = 2001;
    int comb[max_n][max_n];

    for(int i = 0; i < max_n; i++) {
        for(int j = 0; j <= i; j++) {
            if(i == 0 || j == 0) {
                comb[i][j] =1;
            } else {
                comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
            }
        }
    }
    std::vector<int> ans(k);

    for(int i =0; i<=k;i++) {
        ans[i] = comb[n-k+1][i+1] * comb[k-1][i];
        ans[i] = ans[i]%(1000000000+7);
    }
    return ans;
}
