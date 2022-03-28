#include "Hydroplane.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N, M, H, S, T;
	cin >> N >> M >> H >> S >> T;;

	vector<int> A(M);
	vector<int> B(M);
	vector<int> C(M);

    for (int i = 0; i < M; i++) {
        cin >> A[i]>>B[i]>>C[i];
    }
	
	vector<int> X(H);
	vector<int> Y(H);

    for (int i = 0; i < H; i++) {
        cin >> X[i]>>Y[i];
    }
	
	cout<<MinimalCost(N, M, H, S, T, A, B, C, X, Y)<<"\n";
	
	return 0;
}
