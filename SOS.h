/*
    | SOS DP |
    Desc: Compute sum of all subset of a mask in O(n*2^n).
    Source: KawakiMeido
    State: Tested
*/

for (int i=0; i<LG; i++){
    for (int mask=0; mask<(1<<LG); mask++){
        if ((mask&(1<<i))){
            SOS[mask] = SOS[mask]+SOS[mask^(1<<i)];
        }
    }
}
