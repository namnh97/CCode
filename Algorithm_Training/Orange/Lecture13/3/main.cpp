//https://www.spoj.com/problems/SCUBADIV/
#include <bits/stdc++.h>

using namespace std;

const int MAX_OXI = 22;
const int MAX_NITRO  = 80;
const int INF = 100000000;

vector<vector<vector<int>>> dp;
vector<int> oxiCylinder;
vector<int> nitroCylinder;
vector<int> weight;

int solve(int index, int oxiNeed, int nitroNeed) {
    if (dp[index][oxiNeed][nitroNeed] != -1) {
        return dp[index][oxiNeed][nitroNeed];
    }

    if (oxiNeed == 0 && nitroNeed == 0) {
        return dp[index][oxiNeed][nitroNeed] = 0;
    }

    if (index == 0) {
        return dp[index][oxiNeed][nitroNeed] = INF;
    } 

    int donTakeThisCylinder = solve(index-1, oxiNeed, nitroNeed);
    int newOxiNeed = max(oxiNeed - oxiCylinder[index], 0);
    int newNitroNeed = max(nitroNeed- nitroCylinder[index], 0);
    int takeThisCylinder = solve(index-1, newOxiNeed, newNitroNeed) + weight[index];
    dp[index][oxiNeed][nitroNeed] = min(donTakeThisCylinder, takeThisCylinder);
    return dp[index][oxiNeed][nitroNeed];
}


int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    int T;
    cin >> T;
    while (T--) {
        int oxi, nitro;
        cin >> oxi >> nitro;

        int n;
        cin >> n;
        oxiCylinder = vector<int>(n+1);
        nitroCylinder = vector<int>(n+1);
        weight = vector<int>(n+1);
        dp = vector<vector<vector<int> > >(n+1, vector<vector<int>>(MAX_OXI, vector<int>(MAX_NITRO, -1)));
        for (int  i = 1; i <= n; i++) {
            cin >> oxiCylinder[i] >> nitroCylinder[i] >> weight[i];
        }
        solve(n, oxi, nitro);
        cout << dp[n][oxi][nitro] << endl;
    }
    return 0;
}


