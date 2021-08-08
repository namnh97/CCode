//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=545
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

string vowels = "AEOYIU";
int stepX[] = {0, 0, 1, 1, 1, -1, -1, -1};
int stepY[] = {1, -1, 0, 1, -1, 0, 1, -1};
int newline = false;

int countVowel(const string word) {
    int result = 0;
    for (auto &it : word) {
        if (vowels.find(it) != string::npos) {
            result++;
        }
    }   
    return result;
}

void findWord(char board[4][4], int x, int y, string &curWord, bool visited[4][4], set<string>& word) {
    if (curWord.length() == 4) {
        if (countVowel(curWord) == 2) {
            word.insert(curWord);
        }
        return;
    }

    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nextX = x + stepX[i];
        int nextY = y + stepY[i];
        if (nextX >= 0 && nextX < 4 && nextY >= 0 && nextY < 4 && visited[nextX][nextY] == false) {
            string newCurWord = curWord + board[nextX][nextY];
            findWord(board, nextX, nextY, newCurWord, visited, word);
        }
    }
    visited[x][y] = false;
}

void solve() {
    char board[2][4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            char tmp; cin >> tmp;
            if (tmp == '#') {
                exit(0);
            }
            board[j >> 2][i][j & 3] = tmp;
        }
    }

    if (newline == true) {
        cout << endl;
    }
    newline = true;


    bool visited[4][4];
    memset(visited, false, sizeof(visited));
    set<string> words[2];
    for (int boardId : {0, 1}) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                string curWord(1, board[boardId][i][j]);
                findWord(board[boardId], i, j, curWord, visited, words[boardId]);
            }
        }
    }
    vector<string> commonWords;
    for (const string &word : words[0]) {
        if (words[1].find(word) != words[1].end()) {
            commonWords.pb(word);
        }
    }
    if (commonWords.size() == 0) {
        cout << "There are no common words for this pair of boggle boards.\n";
    } else {
        for (auto &word : commonWords) {
            cout << word << endl;
        }
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    while(1) {
        solve();
    }
    return 0;
}


