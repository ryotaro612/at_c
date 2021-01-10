#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> B, C;

pair<int, int> dfs(vector<vector<char>> &board, int index) {
    if(index == 9) {
        int c = 0;
        int n = 0;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == board[i + 1][j]) {
                    c += B[i][j];
                } else {
                    n += B[i][j];
                }
            }
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 2; j++) {
                if(board[i][j] == board[i][j + 1]) {
                    c += C[i][j];
                } else {
                    n += C[i][j];
                }
            }
        }
        return make_pair(c, n);
    }
    bool is_c = (index % 2 == 0);
    int score = 1 << 20;
    if(is_c) {
        score = -score;
    }
    pair<int, int> res;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                if(is_c) {
                    board[i][j] = 'o';
                } else {
                    board[i][j] = 'x';
                }
                pair<int, int> scores = dfs(board, index + 1);
                board[i][j] = ' ';

                if(is_c) {
                    if(scores.first - scores.second > score) {
                        res = scores;
                        score = scores.first - scores.second;
                    }
                } else {
                    if(scores.first - scores.second < score) {
                        res = scores;
                        score = scores.first - scores.second;
                    }
                }
            }
        }
    }
    return res;
}

pair<int, int> solve(vector<vector<int>> b, vector<vector<int>> c) {
    B = b;
    C = c;
    vector<vector<char>> board(3, vector<char>(3, ' '));
    return dfs(board, 0);
}
/*
int main() {
    vector<vector<int>> b(2, vector<int>(3)), c(3, vector<int>(2));

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> c[i][j];
        }
    }
    pair<int, int> res = solve(b, c);
    cout << res.first << endl;
    cout << res.second << endl;
}
*/