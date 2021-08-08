#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 10;
bool board[MAX][MAX];
int nextR[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int nextC[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int dfs(int row, int col) {
    int path = 0;
    board[row][col] = false;
    for (int i = 0; i < 8; i++) {
        int nr = row + nextR[i];
        int nc = col +  nextC[i];
        if (nr >= 0 && nc >= 0 && nr < MAX && nc < MAX && board[nr][nc] == true) {
            path = max(path, dfs(nr, nc));
        }
    }
    board[row][col] = true;
    return path + 1;
}


void solve() {
    int n;
    int cas = 1;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        int startCol = 0, area = 0;
        memset(board, false, sizeof(board));
        for (int i = 0; i < n; i++) {
            int startIndex, nCols;
            cin >> startIndex >> nCols;

            area += nCols;
            if (i == 0) {
                startCol = startIndex;
            }

            for (int j = startIndex; j < startIndex + nCols; j++) {
                board[i][j] = true;
            }
        }
        int maxSteps = dfs(0, startCol);
        int result = area - maxSteps;
        if (result == 1) {
            cout << "Case " << cas++ << ", " << result << " square can not be reached." << endl;
        } else {
            cout << "Case " << cas++ << ", " << result << " squares can not be reached." << endl;
        }
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


