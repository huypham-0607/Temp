/*
    | Lowest Common Ancestor - Binary Lifting |
    Desc: Finding LCA in O(n*log(n)). Can support additional path computations.
    Source: KawakiMeido
    State: Untested lmao
*/

const int LG_LCA = 18

int up[LG_LCA][N];
int depth[N];

void dfsLCA(int u, int p=0){
    depth[u] = depth[p]+1;
    up[0][u] = p;
    for (int lg=1; lg<LG_LCA; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        dfsLCA(v,u);
    }
}

int binLift(int u, int x){
    for (int lg=0; lg<LG_LCA; lg++){
        if ((1<<lg)&x) u = up[lg][u];
    }
    return u;
}

int getDist(int u, int v){
    if (depth[u]>depth[v]) swap(u,v);
    v = binLift(v,depth[v]-depth[u]);
    if (u==v) return u;
    for (int lg=LG_LCA-1; lg>=0; lg--){
        if (up[lg][u]!=up[lg][v]){
            u = up[lg][u];
            v = up[lg][v];
        }
    }
    return up[0][u];
}
