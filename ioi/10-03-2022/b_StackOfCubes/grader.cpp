#include "StackOfCubes.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int N;
    std::cin >> N;
	std::vector<string> stacks(N);
	for(int i=0;i<N;i++){
		cin>>stacks[i];
	}
    std::vector<int> A(N - 1);
	std::vector<int> B(N - 1);
    for (int i = 0; i < N-1; i++) {
        std::cin >> A[i]>>B[i];
    }
    std::cout<<FinalStack(N, stacks, A, B)<<"\n";
    
    return 0;
}