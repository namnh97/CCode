//https://www.spoj.com/problems/SOCIALNE/#:~:text=SOCIALNE%20%2D%20Possible%20Friends&text=Two%20persons%20are%20possible%20friends,help%20him%20in%20this%20task.
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
void debugOut() {
    cerr << endl;
}
const int MAX = 55;
const int INF = 1e9;
vector<vector<char>> connections;
vector<char> line;
map<int, int> possible;


void solve() {
    int t; cin >> t;
    while (t--) {
        connections.clear();
        line.clear();
        possible.clear();

        string s; cin >> s;
        int m = (int)s.size();
        for (int i = 0; i < m; i++) {
            line.pb(s[i]);
        }
        connections.pb(line); line.clear();

        for (int i = 0; i < m - 1; i++) {
            cin >> s;
            for (int j = 0; j < m; j++) {
                line.pb(s[j]);
            }
            connections.pb(line); line.clear();
        }
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (connections[i][j] == 'N') {
                    for (int k = 0; k < m; k++) {
                        if (connections[i][k] == 'Y' && connections[k][j] == 'Y') {
                            cerr << i << " " << k << " " << j << endl;
                            possible[i]++;
                            possible[j]++;
                            break;
                        }
                    }
                }
            }
        }
        int res[2] = {0};
        for (int i = 0; i < m; i++) {
            if (res[1] < possible[i]) {
                res[1] = possible[i];
                res[0] = i;
            }
        }
        cout << res[0] << " " << res[1] << endl;
    }
}



int main(void){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    solve();
    return 0;
}
