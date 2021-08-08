#include<bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef pair<int, int> Incr;
static constexpr Incr UP = mp(-1, 0), DN = mp(1, 0), LT = mp(0, -1), RT = mp(0, 1);
static constexpr Incr NE = mp(-1 ,1), NW = mp(-1, -1), SE = mp(1, 1), SW = mp(1, -1);

struct Tothello{
    typedef vector< vector<int> > Board;
    Board board;

    int doCount(const Board &board){
        int cnt = 0;
        for(int i = 0; i < 8; i++){
            cnt += count(board[i].begin(), board[i].end(), 1);
        }
        return cnt;
    }

    int applyOne(Board &b, Board &c, const Incr &i1, const Incr &i2){
        int cnt = 0;
        for(Iter2d<int> it(b, c, i1), ite = it.end(); it != ite; it++){

        }
    }

    void apply(Board &){
        int cnt;
    }
    int bestMove(vector<string> red, vector<string> blk, string who){
        for(int i = 0; i < 8; i++){
            board.push_back(vector<int>(8, -1));
        }
        int w = (who == "Red" ? 1 : 0);
        for(const auto &s : red){
            board[s[0] - 'A'][s[1] - '1'] = w;
        }
        for(const auto &s : blk){
            board[s[0] - 'A'][s[1] - '1'] = w ^ 1;
        }
        int maxcnt = doCount(board);
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] < 0){
                    Board temp = board;
                    temp[i][j] = 1;
                    apply(temp);
                    maxcnt = max(maxcnt, doCount(temp));
                }
            }
        }
        return maxcnt;
    }

};

int main(void){
    return 0;
}