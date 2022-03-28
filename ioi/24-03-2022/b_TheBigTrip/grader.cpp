#include "TheBigTrip.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

int readInt(){
    int i;
    if(scanf("%d",&i)!=1){
        fprintf(stderr,"Error while reading input\n");
        exit(1);
    }
    return i;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    int N, W;
    N = readInt();
    W = readInt();
    std::vector<int> H(N);
    for(int i=1; i<=N; i++){
        H[i-1] = readInt();
    }
        
    std::vector<long long> ans = GetWaitTimes(N, W, H);
    printf("%lld %lld", ans[0],ans[1]);

    return 0;



}
