#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
using namespace std;

const int MAX = 1005;
bool mark[MAX];
int n, c;

void initSieve() {
    mark[0] = mark[1] = true;
    memset(mark, true, sizeof(mark));
    for (int i = 2; i * i <= MAX;  i++) {
        if (mark[i] == true) {
            for (int j = i * i; j <= MAX; j += i) {
                mark[j] = false;
            }
        }
    }
}

void solve() {
    initSieve();
    while (cin >> n >> c) {
        vector<int> primes;
        for (int i = 1; i <= n; i++) {
            if (mark[i] == true) {
                primes.pb(i);
            }
        }
        cout << n << " " << c << ":";
        int len = primes.size();
        if (len < (2 * c - 1)) {
            for (auto &it : primes) {
                cout << " " << it;
            }
        } else {
            for (int i = (len / 2 - c + (len % 2)); i <= len / 2 + c - 1; i++) {
                cout << " " << primes[i];
            }
        }
        cout << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


