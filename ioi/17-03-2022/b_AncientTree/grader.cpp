#include "AncientTree.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;


void UList(std::vector<int> &U){
	if(U[0]==-1){
		cout<<"Error\n";
	}
	else{
		for(int num:U){
			cout <<num<<"\n";
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N;
	cin >> N;

	vector<int> V(N);

    for (int i = 0; i < N; i++) {
        cin >> V[i]; 
    }
	
	RestoreAncientTree(N, V);
	return 0;
}
