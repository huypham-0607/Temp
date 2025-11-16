/*
    | Sieve of Eratosthenes |
    Desc: Get all primes from 1 to MXP in O(n*log(log(n)))
    Source: KawakiMeido
    State: Untested lmao
*/
const int MXP = 1e6;

vector<int> primes;

void Sieve(){
    bitset<MXP+1> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i*i<=MXP; i++){
        if (!bs[i]) continue;
        for (int j=i*i; j<=MXP; j+=i){
            bs[j]=0;
        }
    }

    for (int i=1; i<=MXP; i++){
        if (bs[i]) primes.push_back(i);
    }
}
