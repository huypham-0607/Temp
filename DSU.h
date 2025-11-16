/*
    | Disjoint Set Union |
    Desc: Maintaining disjoint set in O(n*α(n)).
    Source: KawakiMeido
    State: Untested lmao
*/

//DSU
//

struct DSU{
    int n;
    vector<int> parent;

    void Init(int _n){
        n = _n;
        parent.resize(n,0);
        for (int i=1; i<=n; i++){
            parent[i] = i;
        }
    }

    int Find(int x){
        return (x == parent[x])? x : parent[x] = Find(parent[x]);
    }

    bool IsSame(int u, int v){
        return (Find(u) == Find(v));
    }

    void Union(int u, int v){
        int x = Find(u);
        int y = Find(v);
        if (x!=y){
            parent[y] = x;
        }
    }
};

