//https://codeforces.com/problemset/problem/770/C
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

bool dfs(vector<vector<int>> graph, vector<int> &visited, int course, vector<int> &result, bool &cycle) {
    if (visited[course] == 0) {
        visited[course] = 1;
        for (auto &it : graph[course]) {
            dfs(graph, visited, it, result, cycle);
        }
        visited[course] = 2;
        result.pb(course);
    } else if (visited[course] == 1) {
        cycle = true;
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> mainCourses;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < k; i++) {
        int tmp; cin >> tmp;
        mainCourses.pb(tmp);
    }

    for (int i = 1; i <= n; i++) {
        int nums; cin >> nums;
        for (int j = 0; j < nums; j++) {
            int tmp; cin >> tmp;
            graph[i].pb(tmp);
        }
    }

    vector<int> result;
    vector<int> visited(n + 1, 0);
    bool cycle = false;
    for (int i = 0; i < k; i++) {
        int course = mainCourses[i];
        bool check = dfs(graph, visited, course, result, cycle);
    }

    if (cycle == true) {
        cout << -1;
        return;
    }

    cout << result.size() << endl;
    for (auto &it : result) {
        cout << it << " ";
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


