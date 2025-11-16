/*
    | Centroid Decomposition |
    Desc: Technique for path queries. Takes O(n*log(n)) to build.
    Source: KawakiMeido
    State: Untested lmao
*/

int sz[N];
int vis[N];

int findSize(int u, int p=0){
    sz[u] = 1;
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        sz[u] += findSize(v,u);
    }
    return sz[u];
}

int findCentroid(int u, int n, int p=0){
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        if (sz[v]>n/2) return findCentroid(v,n,u);
    }
    return u;
}

void dfsCentroid(int u, int p, int depth=1){
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        dfsCentroid(v,u,depth+1);
    }
}

void buildCentroid(int s){
    findSize(s);
    int u = findCentroid(s,sz[s]);
    vis[u] = true;

    for (auto v:adj[u]){
        if (vis[v]) continue;
        dfsCentroid(v,u);
    }

    for (auto v:adj[u]){
        if (vis[v]) continue;
        buildCentroid(v);
    }
}
