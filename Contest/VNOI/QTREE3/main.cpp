#include <bits/stdc++.h>
#define pb push_back
 
using namespace std;
 
const int maxn = 1e5;
vector <int> A[maxn+1];
int P[maxn+1], Num[maxn+1], root[maxn+1], ID[maxn+1], IT[4*maxn+1], id[maxn+1], n, q, num, TOPO[maxn+1], Id, C[maxn+1], NUM[maxn+1], ans;
 
void Input()
{
    cin >> n >> q;
    for (int i=1; i<=n-1; i++)
    {
        int u, v;
        cin >> u >> v;
    A[u].pb(v); A[v].pb(u);
    }
}
 
void DFS(int u)
{
    TOPO[u] = ++num;
    NUM[num] = u;
    C[u] = 1;
    for (int i=0; i<A[u].size(); i++)
    {
        int v = A[u][i];
        if (!TOPO[v])
        {
            P[v] = u;
            DFS(v);
            C[u] += C[v];
        }
    }
}
 
void HLD(int u)
{
    if (!root[num]) root[num] = u;
    Num[u] = num;
    ID[u] = ++Id;
    int v = 0;
    for (int i=0; i<A[u].size(); i++)
    {
        int k = A[u][i];
        if (k != P[u] && C[k] > C[v]) v = k;
}
    if (!v) return;
    HLD(v);
    for (int i=0; i<A[u].size(); i++)
    {
        int k = A[u][i];
        if (k != P[u] && k != v) ++num, HLD(k);
    }
}
 
void Built(int k, int l, int r)
{
    if (l == r)
    {
        IT[k] = 1e9;
        id[l] = k;
        return;
    }
    int mid = (l + r)/2;
    Built(k*2, l, mid);
    Built(k*2+1, mid+1, r);
    IT[k] = 1e9;
}
 
void Update(int u)
{
    int k = id[ID[u]];
    int val = TOPO[u];
    if (IT[k] != val) IT[k] = val; else IT[k] = 1e9;
    k/=2;
    while (k != 0)
    {
        IT[k] = min(IT[2*k], IT[2*k+1]);
        k/=2;
    }
}
 
void Query(int k, int l, int r, int i, int j)
{
    if (r < i || l > j) return;
    if (i <= l && r <= j)
    {
        ans = min(ans, IT[k]);
        return;
    }
    int mid = (l + r)/2;
    Query(k*2, l, mid, i, j);
    Query(k*2+1, mid+1, r, i, j);
}
 
void QUERY(int u)
{
    ans = 1e9;
    while (Num[u] != 1)
    {
        Query(1, 1, n, ID[root[Num[u]]], ID[u]);
        u = P[root[Num[u]]];
    }
    Query(1, 1, n, ID[1], ID[u]);
    if (ans == 1e9) cout << -1;
    else cout << NUM[ans];
    cout << "\n";
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    Input();
    DFS(1);
    num = 1;
    HLD(1);
    Built(1, 1, n);
    while (q--)
    {
        int type, u;
        cin >> type >> u;
        if (type == 0) Update(u);
        else QUERY(u);
    }
    return 0;
}