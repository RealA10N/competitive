#include "Presents.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int N, F, S, T;
    std::cin >> N >> F >> S >> T;
    std::vector<int> A(F);
	std::vector<int> B(F);
    for (int i = 0; i < F; i++) {
        std::cin >> A[i] >> B[i];
    }
    
    std::cout<<LastDay(N,F,S,T,A,B)<<"\n";
    
    return 0;
}