#include "Funicular.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;


void PrintFunicular(int u, int v){
	cout<<u<<" "<<v<<"\n";
}

void PrintDistance(int dist){
	cout<<dist<<"\n";
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N;
	cin >> N;

	vector<int> A(N-1);
	vector<int> B(N-1);

    for (int i = 0; i < N - 1; i++) {
        cin >> A[i]>>B[i]; 
    }
	
	ReplaceFunicular(N, A, B);
	
	return 0;
}
