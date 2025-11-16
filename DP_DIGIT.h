/*
    | DP Digit |
    Desc: A general framework for DP Digit
    States would be DP[pos][k][over][under][start] where:
        - pos: The digit position
        - k: An arbitrary state related to the problem
        - over: Whether the current num is guaranteed to be over lower bound
        - under: Whether the current num is guaranteed to be under lower bound
        - started: Whether the number has started (not full 0s)
    Source: KawakiMeido
    State: Untested lmao
*/

int Call_DP(int pos, bool started, bool over, bool under){
    if (pos == sz){
        //Do something
    }

    if (dp[pos][started][over][under] != -1) return dp[pos][started][over][under];


    for (int i=0; i<10; i++){
        if (!over && i<digl) continue;
        if (!under && i>digr) break;
        //Do something
    }
    return dp[pos][started][over][under] = res;
}
