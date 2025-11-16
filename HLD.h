/*
    | Heavy Light Decomposition |
    Desc: BEST TECHNIQUE EVER. Path queries in O(n*log^2(n)) with Segment Tree.
    Source: KawakiMeido
    State: Untested lmao
*/

int curpos = 0;
int parent[N], sz[N], depth[N];
int root[N], pos[N];

void dfsHLD(int u, int p=0){
    sz[u] = 1;
    for (auto v:adj[u]){
        if (v==p) continue;
        parent[v] = u;
        depth[v] = depth[u]+1;
        dfsHLD(v,u);
        sz[u] += sz[v];
    }
}

void buildHLD(int u, int r){
    pos[u] = ++curpos;
    root[u] = r;

    int nxt = 0;

    for (auto v:adj[u]){
        if (v==parent[u]) continue;
        if (!nxt || sz[v]>sz[nxt]) nxt = v;
    }

    if (nxt){
        buildHLD(nxt,r);
    }

    for (auto v:adj[u]){
        if (v==parent[u] || v==nxt) continue;
        buildHLD(v,v);
    }
}

void updateHLD(int x){
    int u = x;
    while (root[u]!=1){
        int v = parent[root[u]];

        u = v;
    }
}
