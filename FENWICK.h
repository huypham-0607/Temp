/*
    | Fenwick Tree |
    Desc: Point update range query / Range update point query in O(n*log(n))
    Source: KawakiMeido
    State: Untested lmao
*/

struct Fenwick{
    vector<int> BIT;

    Fenwick(int _n=0): n(_n){
        BIT.resize(n+10);
    }

    void Init (int _n, int val=0){
        BIT.resize(n+10,0);
    }

    void update(int idx, int val){
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int getPoint(int idx){
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    int getVal(int l, int r){
        return (getPoint(r)-getPoint(l-1));
    }
}
