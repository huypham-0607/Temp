/*
    | Knuth-Morris-Pratt |
    Desc: Single string matching in O(n)
    Source: KawakiMeido
    State: Untested lmao
*/

pi[0] = 0;
for (int i=1; i<(int)s.size(); i++){
    int cur = i;
    while (cur!=0){
        if (s[i]==s[pi[cur-1]]){
            pi[i] = pi[cur-1]+1;
            break;
        }
        cur = pi[cur-1];
    }
    if (cur == 0){
        if (s[i] == s[0]) pi[i] = 1;
        else pi[i] = 0;
    }
}
