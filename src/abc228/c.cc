#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
vector<string> solve(int n, int k, vector<vector<int>> &p) {
	unordered_multiset<int> scores_set;
	rep(i, n) {
		int sum = p[i][0] + p[i][1] + p[i][2];
		scores_set.insert(sum);
	}
	vector<int> scores;
	for(auto score: scores_set)
		scores.push_back(score);
	sort(scores.begin(), scores.end());

	vector<string> res(n);
	rep(i, n) {
		int sum = p[i][0] + p[i][1] + p[i][2];
		auto iter = upper_bound(scores.begin(), scores.end(), sum+300);
		if(iter == scores.end()) {
			res[i] = "Yes";
			continue;
		} else {
			//int rank = distance(iter, scores.end()) + 1;
			int rank = (scores.end() - iter)  + 1;
			if(rank <= k) {
				res[i] = "Yes";
			} else {
				res[i] = "No";
			}

		}
	}
	return res;
}


#ifdef ONLINE_JUDGE
int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> p(n, vector<int>(3));
    rep(i, n) {
        rep(j, 3) { cin >> p[i][j]; }
    }
    vector<string> res = solve(n, k, p);
    for(auto yn : res)
        cout << yn << endl;
    return 0;
}
#endif
