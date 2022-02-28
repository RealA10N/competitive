#include "LionAndGrapes.h"
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
    int N,M;
    std::cin >> N >> M;
	std::vector<vector<char>> world(N,vector<char>(M));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>world[i][j];
		}
	}
    std::cout<< Grapes(N, M, world)<<"\n";
    
    return 0;
}