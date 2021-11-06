#include<iostream>
#include<algorithm>
using namespace std;
int N,K,A[8],ord[8]={0,1,2,3,4,5,6,7},cnt;
void perm(int idx){
	if(idx==N){
		int wei=500;
		for(int i=0;i<N;++i){
			wei-=K;
			wei+=A[ord[i]];
			if(wei<500) return;
		}
		cnt++;
		return;
	}
	for(int i=idx;i<N;++i){
		swap(ord[i],ord[idx]);
		perm(idx+1);
		swap(ord[i],ord[idx]);
	}
}
int main(){
	cin>>N>>K;
	for(int i=0;i<N;++i) cin>>A[i];
	perm(0);
	cout<<cnt<<'\n';
}
