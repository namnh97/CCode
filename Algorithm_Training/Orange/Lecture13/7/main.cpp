#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

const int MAX = 20000;
const int INF = 1000000;
int coinCount[MAX];

void solve() {
    int nTest; cin >> nTest;
    while (nTest--) {
        int itemPrice; cin >> itemPrice;
        int n; cin >> n;
        int coins[n];

        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }

        coinCount[0] = 0;
        for (int i = 1; i <= MAX - 1; i++) {
            coinCount[i] = INF;
        }

        for (int i = 0; i < n; i++) {
            for (int j = itemPrice; j >= 0; j--) {
                if (coinCount[j] != INF) {
                    coinCount[j + coins[i]] = min(coinCount[j + coins[i]], coinCount[j] + 1);
                }
            }
        }

        for (int i = itemPrice; i < MAX; i++) {
            if (coinCount[i] < INF) {
                cout << i << " " << coinCount[i] << endl;
                break;
            }
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