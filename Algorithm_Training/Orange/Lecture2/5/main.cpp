//https://www.hackerrank.com/challenges/sansa-and-xor/problem
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

void solve() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int result = 0;
        for (int i = 1; i <= n; i++) {
            int tmp; cin >> tmp;
            if ( ((long long) (n - i + 1) * i % 2) == 1) {
                result = result ^ tmp;
            }
        }   
        cout << result << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


