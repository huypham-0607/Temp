/*
    | Dijkstra |
    Desc: Single-source shortest path in O(n*log(n))
    Source: KawakiMeido
    State: Untested lmao
*/

void dijkstra(int s, int dist[]){
    for (int i=1; i<=n; i++){
        dist[i] = INF;
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[s] = 0;
    pq.push({0,s});
    while (!pq.empty()){
        int u = pq.top().se;
        int d = pq.top().fi;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto in:a[u]){
            int v = in.fi;
            int delta = in.se;
            if (dist[v] > d+delta){
                dist[v] = d+delta;
                pq.push({d+delta,v});
            }
        }
    }
}
