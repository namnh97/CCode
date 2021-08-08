#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int N = 8;
int board[N][N];
bool visited[N][N];
int t, res;

bool check(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (visited[i][col]) return false;
    }

    for (int i = row, j = col; i >= 0  && j >= 0; i--, j--) {
        if (visited[i][j]) return false;
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (visited[i][j]) return false;
    }
    return true;
}

void backtracking(int row, int scores) {
    if (row == N) {
        res = max(res, scores);
        return;
    }
    for (int j = 0; j < N; j++) {
        if (check(row, j) == true) {
            visited[row][j] = 1;
            backtracking(row + 1, scores + board[row][j]);
            visited[row][j] = 0;
        }
    }
}

void solve() {
    cin >> t;
    while (t--) {
        res = 0;
        memset(visited, false, N * N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }
        backtracking(0, 0);
        cout << res << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


