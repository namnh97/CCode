//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2001
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 1e5;
map<string, int> mpBeverages;
vector<int>  graph[MAX];
vector<string> names;
vector<int> result;

void init() {
    for (int i = 0; i < MAX; i++) {
        graph[i].clear();
    }
    mpBeverages.clear();
    names.clear();
    result.clear();
}

void topologicalSort(vector<int> graph[], vector<int> &result) {
    vector<int> inDegree(mpBeverages.size(), 0);
    for (int i = 0; i < mpBeverages.size(); i++) {
        for (auto &it : graph[i]) {
            inDegree[it]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> zeroDegrees;
    for (int i = 0; i < mpBeverages.size(); i++) {
        if (inDegree[i] == 0) {
            zeroDegrees.push(i);
        }
    }

    while (zeroDegrees.empty() == false) {
        int u = zeroDegrees.top(); zeroDegrees.pop();
        result.push_back(u);
        for (auto &it : graph[u]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                zeroDegrees.push(it);
            }
        }
    }
}

void solve() {
    int n;
    int nTest = 0;
    while (cin >> n) {
        init();

        int count = 0;
        for (int i = 0; i < n; i++) {
            string beverage; cin >> beverage;
            names.push_back(beverage);
        }   

        for (int i = 0; i < n; i++) {
            mpBeverages[names[i]] = i;
        }

        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            string b1, b2; cin >> b1 >> b2;
            int nB1 = mpBeverages[b1];
            int nB2 = mpBeverages[b2];
            graph[nB1].pb(nB2);
        }

        topologicalSort(graph, result);
        cout << "Case #" << ++nTest << ": Dilbert should drink beverages in this order:";
        for (auto &it : result) {
            cout << " " << names[it];
        }
        cout << "." << endl << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


