#include <cstring>

#include <vector>

#include <list>

#include <map>

#include <set>

#include <queue>

#include <deque>

#include <stack>

#include <bitset>

#include <algorithm>

#include <functional>

#include <numeric>

#include <utility>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cmath>

#include <climits>

#include <cstdlib>

#include <ctime>

#include <memory.h>

#include <cassert>

#define FOR(i, a, b) for(int i = (a); i < (b); i++)

#define REP(i, a, b) for(int i = (a); i <=(b); i++)

#define FORD(i, a, b) for(int i = (a); i > (b); i--)

#define REPD(i, a, b) for(int i = (a); i >=(b); i--)

#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

#define RESET(a, v) memset((a), (v), sizeof((a)))

#define SZ(a) (int((a).size()))

#define ALL(a) (a).begin(), (a).end()

#define PB push_back

#define MP make_pair

#define LL long long

#define LD long double

#define II pair<int, int>

#define X first

#define Y second

#define VI vector<int>

const int N = 50;

const int M = 1000;

using namespace std;

int res[N][N];

int c[M][M], f[M][M], T[M];

VI a[M];

int n, nn, s, t, totalFlow;

 

bool bfs() {

    queue<int> Q;

    Q.push(s);

    REP(i, 1, nn) T[i] = 0;

    while (!Q.empty()) {

        int u = Q.front(); Q.pop();

        TR(v, a[u]) if (T[*v] == 0 && c[u][*v] > f[u][*v]) {

            T[*v] = u;

            if (*v == t) return 1;

            Q.push(*v);

        }

    }

    return 0;

}

 

void incFlow() {

    int delta = INT_MAX;

    for(int v = t; v != s; v = T[v])

        delta = min(delta, c[T[v]][v] - f[T[v]][v]);

    for(int v = t; v != s; v = T[v])

        f[T[v]][v] += delta, f[v][T[v]] -= delta;

    totalFlow += delta;

}

 

bool canBeChampion(int team) {

    int points[N];

    RESET(points, 0);

    REP(i, 1, n) REP(j, 1, n) if (res[i][j] == 1) points[i] += 3;

    REP(i, 1, n) if (res[team][i] == 2) points[team] += 3;

    if (*max_element(points + 1, points + 1 + n) > points[team]) return 0;

    s = 1; nn = t = 2;

    REP(i, 1, n) {

        c[++nn][t] = (points[team] - points[i]) / 3;

        a[nn].PB(t);

    }

    int need = 0;

    REP(i, 1, n) REP(j, i + 1, n) if (i != team && j != team && res[i][j] == 2) {

        ++nn; ++need;

        c[s][nn] = c[nn][i + 2] = c[nn][j + 2] = 1;

        a[s].PB(nn); a[nn].PB(s);

        a[nn].PB(i + 2); a[i + 2].PB(nn);

        a[nn].PB(j + 2); a[j + 2].PB(nn);

    }

    totalFlow = 0;

    while (bfs()) incFlow();

    REP(i, 1, nn) a[i].clear();

    REP(i, 1, nn) REP(j, 1, nn) c[i][j] = f[i][j] = 0;

    return totalFlow == need;

}

 

int main() {

    ios :: sync_with_stdio(0); cin.tie(0);

    cin >> n;

    REP(i, 1, n) REP(j, 1, n) cin >> res[i][j];

    REP(i, 1, n) cout << canBeChampion(i);

    return 0;

}

 