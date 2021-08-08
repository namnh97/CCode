#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;
const int N = 30007, Q = 200007, MAX = 10000007;

int n, q, ans[Q], last[MAX], bit[N];

struct query {
    int u, v, id;
    bool operator < (const query &q) const {
        return u < q.u;
    }
}qry[Q];

pair<int, int> a[N];

void enter() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = make_pair(last[x], i);
        last[x] = i;
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> qry[i].u >> qry[i].v;
        qry[i].id = i; //to save order of query
    }
}

void increase(int v) {
    for (; v <= n; v += v & -v) ++bit[v];
}

int sum(int v) {
    int res = 0;
    for (; v != 0; v -= v & -v) res += bit[v];
    return res;
}

void solve() {
    sort(qry + 1, qry + q + 1);
    sort(a + 1, a + n + 1);
    int p = n;
    for (int i = q; i >= 1; i--) {
        query Q = qry[i];
        while (a[p].first >= Q.u) increase(a[p--].second);
        ans[Q.id] = (Q.v - Q.u + 1) - (sum(Q.v) - sum(Q.u));
    }
}

void print() {
    for (int i = 1; i <= q; i++) {
        cout << ans [i] << endl;
    }
}

int main(void){
    enter();
    solve();
    print();
	return 0;
}
