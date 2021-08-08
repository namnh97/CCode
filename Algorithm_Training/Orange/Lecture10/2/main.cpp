#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    if (N == 1){
        cout << K << endl;
        return;
    }
    vector<int> endWith0(20);
    vector<int> endNot0(20);
    endNot0[1] = K -1;

    for (int i = 2; i <= N; i++) {
        endWith0[i] = endNot0[i - 1];
        endNot0[i]= (endNot0[i - 1] + endWith0[i - 1]) * ( K - 1);
    }
    cout << endNot0[N]+ endWith0[N]<< endl;
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


