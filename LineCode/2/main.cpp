#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int INF = 1e5;

void solve() {
    int n;
    cin >> n;
    set<pii> houses;
    for (int i = 0; i < n; i++) {
        int index, loc;
        cin >> index >> loc;
        houses.insert({loc, index});
    }
    int q;
    int res = 0;
    while (cin >> q) {
        pii fiHouse = {INF, INF}, seHouse = {INF, INF};
        set<pii>::iterator pos = houses.lower_bound(pair<int, int>(q, INF));
        if ((pos != houses.begin())) {
            pos--;
            fiHouse = *pos;
            pos++;
        }
        if ((pos != houses.end())) {
            seHouse = *pos;
        }
        if ( abs(fiHouse.first - q) <= abs(seHouse.first - q)) {
            cout << fiHouse.second;
        } else {
            cout << seHouse.second;
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


