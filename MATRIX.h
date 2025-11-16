/*
    | Matrix Template |
    Desc: Template for Matrix operations.
    Source: KawakiMeido
    State: Untested but new code
*/

const int LG = 30;

struct Matrix{
    int n,m;
    vector<vector<int>> val;

    Matrix(int _n=0, int _m=0){
        n = _n;
        m = _m;
        val.resize(n,vector<int>(m,0));
    }

    friend Matrix mul (Matrix a, Matrix b){
        if (a.m!=b.n) return Matrix();
        Matrix res(a.n,b.m);
        for (int i=0; i<a.n; i++){
            for (int j=0; j<b.m; j++){
                for (int k=0; k<a.m; k++){
                    res.val[i][j] = (res.val[i][j] + a.val[i][k]*b.val[k][j]%MD)%MD;
                }
            }
        }
        return res;
    }
};

Matrix matrixExp(Matrix a, int b){
    Matrix res(a.n,a.n);
    for (int i=0; i<a.n; i++){
        res.val[i][i] = 1;
    }
    for (int lg=LG-1; lg>=0; lg--){
        res = mul(res,res);
        if ((1LL<<lg)&b) res = mul(res,a);
    }
    return res;
}