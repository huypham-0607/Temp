/*
    | Trie |
    Desc: Multiple string matching in O(max(s.size())) for all operations
    Source: KawakiMeido
    State: VERY Untested and old code lmao
*/

struct Trie{

    struct Node{
        Node* child[2];
        int cnt;
        int l,r;
        Node(){
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };

    Node* Root;
    int cnt;
    Trie(){
        Root = new Node();
        cnt = 0;
    }

    void Init(){
        clr(Root);
    }
    void clr(Node* cur){
        if (cur->child[0]!=NULL){
            clr(cur->child[0]);
            cur->child[0]=NULL;
        }
        if (cur->child[1]!=NULL){
            clr(cur->child[1]);
            cur->child[1]=NULL;
        }
        if (cur!=Root) delete cur;
    }

    void Add(int x, int pos){
        Node* cur = Root;
        for (int i=29; i>=0; i--){
            int idx = ((x>>i)&1);
            if (cur->child[idx] == NULL) cur->child[idx] = new Node();
            cur = cur->child[idx];
            cur->cnt++;
        }
    }
    int Get(int x, Node* cur, int lg){
        int res = 0;
        if (cur->cnt<=0) return INF;
        for (int i=lg; i>=0; i--){
            int idx = ((x>>i)&1);
            if (cur->child[idx] == NULL){
                res = res+(1<<i);
                cur = cur->child[(idx+1)%2];
            }
            else{
                cur = cur->child[idx];
            }
        }
        return res;
    }
};

Trie TR;
