/*
    | Segment Tree |
    Desc: Classic segment tree. Point Update Range Queries in O(n*log(n)).
    Source: KawakiMeido
    State: Untested lmao
*/

struct SegmentTree{
    struct Node{
        int val;
        Node(){
            val = INF;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node l, Node r){
        if (l.val == INF) return r;
        if (r.val == INF) return l;

        Node i;
        //Update logic

        return i;
    }

    void build(int idx, int l, int r){
        if (l==r){
            //Update logic
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, Node val){
        if (r < x || x < l) return;
        if (l==r){
            //Update logic
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val);
        update(idx*2+1,mid+1,r,x,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    Node getNode(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return Node();
        if (x <= l && r <= y){
            return IT[idx];
        }

        int mid = (l+r)/2;
        return comb(getNode(idx*2,l,mid,x,y),getNode(idx*2+1,mid+1,r,x,y));

    }

    void init(int _n){
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }
};
