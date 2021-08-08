//https://codeforces.com/problemset/problem/242/C
#include<iostream>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair

using namespace std;

const long long INF = 1000000000;
set<long long> points;
map<long long, int> dist;
int stepX[] = {0, 0, 1, 1, 1, -1, -1, -1};
int stepY[] = {1, -1, 0, 1, -1, 0, 1, -1};
long long x0, y0, x1, y1;
int n;

long long getHash(long long x, long long y) {
    return x * 1000000000LL + y;
}

void bfs() {
    queue<long long> q;
    long long s = getHash(x0, y0);
    q.push(s);
    dist[s] = 0;

    while(!q.empty()) {
        long long u = q.front(); q.pop();
        long long x = u / INF;
        long long y = u % INF;
        for (int i = 0; i < 8; i++) {
            long long nextX = x + stepX[i];
            long long nextY = y + stepY[i];
            long long v = getHash(nextX, nextY);
            if (nextX >= 1 && nextX <= INF && nextY >= 1 && nextY <= INF && (points.find(v) != points.end())) {
                if (dist.find(v) == dist.end()) {
                    dist[v] = dist[u] + 1;
                    if (v == getHash(x1, y1)) {
                        cout << dist[v];
                        return;
                    }
                    q.push(v);
                }
            }
        }
    }
    cout << -1;
}

void solve() {
    cin >> x0 >> y0 >> x1 >> y1;
    cin >> n;
    points.insert(getHash(x0, y0));
    points.insert(getHash(x1, y1));
    for (int i = 0; i < n; i++) {
        int r, left, right;
        cin >> r >> left >> right;
        for (long long j = left; j <= right; j++) {
            points.insert(getHash(r, j));
        }
    }
    bfs();
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


