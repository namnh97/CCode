//https://www.spoj.com/problems/UCI2009D/
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

int n, h;
void permutation(int n, int h, int index, int start, string res) {
    if (index == h) {
        cout << res << endl;
        return;
    }
    for (int i = n - h + index; i >= start; i--) {
        res[i] = '1';
        permutation(n, h, index + 1, i + 1, res);
        res[i] = '0';
    }
}

void solve() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> h;
        string res(n, '0');
        permutation(n, h, 0, 0, res);
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}