#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> v[1001];
bool fin,visited[1001];
struct maze{
	char type;
	int p;
}arr[1001];
void dfs(int idx,int g){
	if(arr[idx].type=='L') 
		g=g<arr[idx].p?arr[idx].p:g;
	if(arr[idx].type=='T'){
		g-=arr[idx].p;
		if(g<0) return;
	}
	if(idx==n){
		fin=true;
		return;
	}
	visited[idx]=true;
	for(int i=0;i<v[idx].size();++i){
		int ni=v[idx][i];
		if(!visited[ni])
			dfs(ni,g);
	}
	visited[idx]=false;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(true){
		cin>>n;
		if(n==0) break;
		fin=false;
		for(int i=1;i<=n;++i){
			v[i].clear();
			char a;
			int b;
			cin>>a>>b;
			arr[i]={a,b};
			while(true){
				cin>>b;
				if(b==0) break;
				v[i].push_back(b);
			}
		}
		dfs(1,0);
		if(fin) cout<<"Yes\n";
		else cout<<"No\n";
	}
}
