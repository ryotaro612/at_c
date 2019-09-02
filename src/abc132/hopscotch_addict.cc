#include<queue>
#include<climits>
#include<vector>
#include<iostream>

int solve_hopscotch_addict(int n, int m, int u[], int v[], int s, int t) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;
    int d_size = 3*n;
    std::vector<int> edges[d_size];
    int d[d_size];

    for(int i=0;i<d_size;i++) {
        d[i] = INT_MAX;
    }
    for(int i=0;i<m;i++) {
        edges[u[i] - 1].push_back(v[i] - 1 + n);
        edges[u[i] - 1 + n].push_back(v[i] - 1 + n + n);
        edges[u[i] - 1 + n + n].push_back(v[i] - 1);
    }

    queue.push(std::pair<int, int>(0, s-1));
    d[s-1] = 0;

    while(!queue.empty()) {
        std::pair<int, int> p = queue.top();
        queue.pop();

        std::vector<int> neighbors = edges[p.second];
        for(int i=0;i<neighbors.size();i++) {
            int neighbor = neighbors.at(i);
            if(d[neighbor] > p.first + 1) {
                d[neighbor] = p.first + 1;
                queue.push(std::pair<int, int>(d[neighbor], neighbor));
            }
        }
    }
    int goal_index = t-1;
    return d[goal_index] == INT_MAX ? -1 : d[goal_index] / 3;
}