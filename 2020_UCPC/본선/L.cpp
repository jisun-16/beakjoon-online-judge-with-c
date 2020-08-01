#include<iostream>
using namespace std;
int N, arr[1000], d[1000][1000], k;
int sol(int s, int e, int a, int b){
	if(d[s][e]!=-1)	return d[s][e];
	int first, second;
	if(a<=b){
		if(s==e)	return d[s][e]=arr[(k+s)%(N-1)];
		first=sol(s+1, e, arr[(k+s)%(N-1)], b-a)+arr[(k+s)%(N-1)];
		second=sol(s, e-1, arr[(k+e)%(N-1)], b-a)+arr[(k+e)%(N-1)];
		return d[s][e]=max(first, second);
	}
	else if(a>b){
		if(s==e)	return d[s][e]=0;
		first=sol(s+1, e, a-b, arr[(k+s)%(N-1)])+arr[(k+s)%(N-1)];
		second=sol(s, e-1, a-b, arr[(k+e)%(N-1)])+arr[(k+e)%(N-1)];
		return d[s][e]=min(first, second);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)	cin>>arr[i];
	int ans=0, t;
	for(k=0;k<N;++k){
		fill(&d[0][0], &d[N-1][N], -1);
		t=sol(1, N-1, arr[k], 0)+arr[k];
		if(ans<t)	ans=t;
	}
	cout<<ans<<"\n";
	return 0;
}
