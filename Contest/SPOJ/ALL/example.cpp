
#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct edge
{
    int to, next;
} g[N*2];

int cnt, head[N];
int _deg[N], deg[N];
int n, m, k;
vector<int> vec1, vec2;

inline void add_edge(int v, int u)
{
    g[cnt].to = u, g[cnt].next = head[v], head[v] = cnt++;
}

int bfs1()
{
    int num = 0;
    for(size_t i = 0; i < vec1.size(); i++)
    {
        num++;
        int v = vec1[i];
        for(int i = head[v]; i != -1; i = g[i].next)
        {
            int u = g[i].to;
            if(--deg[u] == 0)
            {
                if(u <= n) vec1.push_back(u);
                else vec2.push_back(u);
            }
        }
    }
    vec1.clear();
    return num;
}
int bfs2()
{
    int num = 0;
    for(size_t i = 0; i < vec2.size(); i++)
    {
        num++;
        int v = vec2[i];
        for(int i = head[v]; i != -1; i = g[i].next)
        {//所依赖的点已安装，把当前点放入相应的序列
            int u = g[i].to;
            if(--deg[u] == 0)
            {
                if(u <= n) vec1.push_back(u);
                else vec2.push_back(u);
            }
        }
    }
    vec2.clear();
    return num;
}
void init()
{
    vec1.clear();
    vec2.clear();
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) vec1.push_back(i);
    for(int i = n+1; i <= n+m; i++)
        if(deg[i] == 0) vec2.push_back(i);
}
int work()
{
    int cnt = 0, res1 = 0, res2 = 0;
    for(int i = 1; i <= n+m; i++) deg[i] = _deg[i];
    init();
    while(true)
    {
        cnt += bfs1();
        res1++;
        if(cnt == n+m) break;
        cnt += bfs2();
        res1++;
        if(cnt == n+m) break;
    }
    cnt = 0;
    for(int i = 1; i <= n+m; i++) deg[i] = _deg[i];
    init();
    while(true)
    {
        cnt += bfs2();
        res2++;
        if(cnt == n+m) break;
        cnt += bfs1();
        res2++;
        if(cnt == n+m) break;
    }
    return min(res1, res2);
}
int main()
{
    while(scanf("%d%d%d", &n, &m, &k), n || m || k)
    {
        cnt = 0;
        memset(head, -1, sizeof head);
        memset(_deg, 0, sizeof _deg);
        for(int i = 0; i < k; i++)
        {
            int v, u;
            scanf("%d%d", &v, &u);
            add_edge(u, v);
            _deg[v]++;
        }
        printf("%d\n", work() + 1);
    }
    return 0;
}