#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;
int calLIS(vector<int> moves) {
    vector<int> sub;
    sub.pb(moves[0]);

    for (int i = 0; i < moves.size(); i++) {
        if (moves[i] < sub[0]) {
            sub[0] = moves[i];
        } else if (moves[i] > sub[sub.size() - 1]) {
            sub.pb(moves[i]);
        } else {
            int position = lower_bound(sub.begin(), sub.end(), moves[i]) - sub.begin();
            sub[position] = moves[i];
        }
    }

    return sub.size();
}

void solve() {
    int nTest; cin >> nTest;
    for (int test = 1; test <= nTest; test++) {
        int n, p, q; cin >> n >> p >> q;
        vector<int> princeMoves(n * n + 5, -1), princessMoves;
        for (int i = 1; i <= p + 1; i++) {
            int x; cin >> x;
            princeMoves[x] = i;
        }


        for (int i = 1; i <= q + 1; i++) {
            int y; cin >> y;
            if (princeMoves[y] != -1) {
                princessMoves.pb(princeMoves[y]);
            }
        }
        int result = calLIS(princessMoves);
        cout << "Case " << test << ": " << result << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


