#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;
int n,d;
int vx[30],vy[30];
int f[1111][1111];

int dfs(int x, int y) {
    int bx, by;
    bx = x + 500;
    by = y + 500;
    if (f[bx][by] != -1) return f[bx][by];
    if (x * x + y * y >= d * d) return 1;
    for (int i = 1; i <= n; i++) {
        if (!dfs(x + vx[i], y + vy[i])) return f[bx][by] = 1;
    }
    return f[bx][by] = 0;
}

int main() {
    int x, y;
    memset(f, -1, sizeof(f));
    cin >> x >> y >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> vx[i] >> vy[i];
    }
    if (dfs(x, y)) {
        cout <<"Anton" << endl;
    } else {
        cout << "Dasha" << endl;
    }
    return 0;
}