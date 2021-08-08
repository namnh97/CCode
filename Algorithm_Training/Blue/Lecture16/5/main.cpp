//https://codeforces.com/problemset/problem/217/A
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 105;
int parent[MAX];

int findRoot(int u)
{
    while (u != parent[u])
    {
        u = parent[u];
    }
    return u;
}

void doUnion(int u, int v)
{
    int pu = findRoot(u);
    int pv = findRoot(v);
    parent[pu] = pv;
}

void solve()
{
    int t;
    cin >> t;
    vector<pii> drifts;
    for (int i = 0; i < t; i++)
    {
        parent[i] = i;
        int u, v;
        cin >> u >> v;
        drifts.push_back({u, v});
        for (int j = 0; j < i; j++) {
            if (drifts[i].first == drifts[j].first || drifts[i].second == drifts[j].second)
            {
                doUnion(i, j);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < t; i++)
    {
        if (i == parent[i])
        {
            res++;
        }
    }
    cout << --res;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
#endif
    solve();
    return 0;
}