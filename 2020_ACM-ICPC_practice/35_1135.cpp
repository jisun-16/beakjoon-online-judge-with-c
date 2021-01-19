#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> adj[51];

bool cmp(int a,int b){ return a>b; }

int dfs(int idx){
	int size=adj[idx].size(),ret=0;
	
	if(size==0) return 0;//leaf
	
	int time[51]={0,};
	for(int i=0;i<size;++i)
		time[i]=dfs(adj[idx][i]);
		
	sort(time,time+size,cmp);//오래 걸리는 순으로 정렬 
	for(int i=0;i<size;++i)
		if(ret<time[i]+i+1)
			ret=time[i]+i+1;
	
	return ret;
}

int main(){
	int p;
	cin>>n;
	cin>>p;
	for(int i=1;i<n;++i){
		cin>>p;
		adj[p].push_back(i);
	}
	
	cout<<dfs(0)<<'\n';
}
