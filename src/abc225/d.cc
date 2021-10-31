#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

struct Node {
    int index;
    Node *prev, *next;
	Node(int index): index(index) {
		prev = next = nullptr;
	}
};

vector<vector<int>> solve(int n, int q, vector<vector<int>> queries) {
    vector<Node *> nodes(n);
    rep(i, n) { 
		nodes[i] = new Node(i);
	}
    vector<vector<int>> res;
    rep(i, q) {
        vector<int> query = queries[i];
        if(query[0] == 1) {
            int x = query[1] - 1, y = query[2] - 1;
            nodes[x]->next = nodes[y];
            nodes[y]->prev = nodes[x];
        } else if(query[0] == 2) {
            int x = query[1] - 1, y = query[2] - 1;
            nodes[x]->next = nullptr;
            nodes[y]->prev = nullptr;
        } else {
            int x = query[1] - 1;
            Node *node = nodes[x];
            while(node->prev != nullptr) {
                node = node->prev;
            }
            vector<int> trains;
            while(node != nullptr) {
                trains.push_back(node->index + 1);
                node = node->next;
            }
			reverse(trains.begin(), trains.end());
			trains.push_back(trains.size());
			reverse(trains.begin(), trains.end());
            res.push_back(trains);
        }
    }
    return res;
}

#ifndef _debug
int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> queries(q);
    rep(i, q) {
        int a;
        cin >> a;
        if(a < 3) {
            vector<int> step(3);
            step[0] = a;
            cin >> step[1] >> step[2];
            queries[i] = step;
        } else {
            vector<int> step(2);
            step[0] = a;
            cin >> step[1];
            queries[i] = step;
        }
    }
    vector<vector<int>> res = solve(n, q, queries);
    rep(i, res.size()) {
        rep(j, res[i].size()) {
            cout << res[i][j];
            if(j == res[i].size() - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    return 0;
}
#endif