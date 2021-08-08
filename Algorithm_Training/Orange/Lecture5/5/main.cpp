#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<bool> marked(n);

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        marked[tmp] = true;
    }

    int res = 1;
    for (int i = 0; i < n; i++) {
        if (marked[i] == false) {
           res++;
        }
   }
    cout << res;
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}