//https://vjudge.net/problem/Kattis-brexitnegotiations
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 1e6 + 5;
int n, u, k;
vector<int> graph[MAX];
int e[MAX];

int topo() {
    vector<int> inDegrees(n + 1, 0);
    priority_queue<pii, vector<pii>, greater<pii>> zeroDegrees;
    for (int i = 1; i <= n; i++) {
        for (auto &it : graph[i]) {
            inDegrees[it]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (inDegrees[i] == 0) {
            zeroDegrees.push(make_pair(e[i], i));
        }
    }
    
    int nMeetingAfter = n - 1;
    int res = -1;
    while (!zeroDegrees.empty()) {
        pii pTop = zeroDegrees.top();
        zeroDegrees.pop();
        int u = pTop.second;
        int cost = pTop.first;
        
        res = max(res, cost + nMeetingAfter);
        nMeetingAfter--;
        
        for (auto &it : graph[u]) {
            inDegrees[it]--;
            if (inDegrees[it] == 0) {
                zeroDegrees.push(make_pair(e[it], it));
            }
        }
    }

    return res;
}
void solve() {
   cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> e[i] >> k;
        for (int j = 0; j < k; j++) {
            int tmp; cin >> tmp;
            graph[i].pb(tmp);
        }
    }
    int result = topo();
    cout << result;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


