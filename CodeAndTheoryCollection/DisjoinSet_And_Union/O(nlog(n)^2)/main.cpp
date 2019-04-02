//how many vertices in substree of vertex
int sz[maxn];

//function calculate the size of the subtree for all methods
void getsz(int v, int p){
    sz[v] = 1;
    for(auto u : g[v]){
        if(u != p){
            getsz(u, v);
            sz[v] += sz[u];
        }
    }
}

map<int, int> *cnt[maxn];
void dfs(int v, int p){
    int mx = -1, bigChild = -1;
    for(auto u : g[v]){
        if(u != p){
            dfs(u, v);
            if(sz[u] > mx){
                mx = sz[u];
                bigChild = u;
            }
        }
    }
    if(bigChild != -1){
        cnt[v] = cnt[bigChild];
    }else{
        cnt[v] = new map<int, int> ();
    }
    (*cnt[v])[ col[v] ]++;
    for(auto u : g[v]){
        if(u != p && u != bigChild){
            for(auto x : *cnt[u]){
                (*cnt[v])[x.first] += x.second;
                //the number of vertices in subtree of vertex v that has color c.
            }
        }
    }
}