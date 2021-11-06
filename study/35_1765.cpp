#include<cstdio>

int n,m,idx,en[1001],p[1001];
bool adj[1001][1001],visited[1001];

void dfs(int i){
	if(visited[i]) return;
	visited[i]=true;
	for(int j=1;j<=n;++j)
		if(adj[i][j]&&!visited[j]) dfs(j);
}

int main(){
	scanf("%d",&n);
	scanf("%d",&m);
	
	for(int i=0;i<m;++i){
		char a;
		int b,c;
		
		scanf(" %c %d %d",&a,&b,&c);
		
		if(a=='E'){
			if(en[b]&&en[c]){
				int be=en[b]%2?en[b]+1:en[b]-1,ce=en[c]%2?en[c]+1:en[c]-1;
				int p1=p[en[b]],p2=p[be],p3=p[en[c]],p4=p[ce];
				adj[p1][p4]=adj[p4][p1]=true;
				adj[p2][p3]=adj[p3][p2]=true;
			}
			else if(en[b]){
				int be=en[b]%2?en[b]+1:en[b]-1;
				en[c]=be;
				adj[c][p[be]]=adj[p[be]][c]=true;
			}
			else if(en[c]){
				int ce=en[c]%2?en[c]+1:en[c]-1;
				en[b]=ce;
				adj[b][p[ce]]=adj[p[ce]][b]=true;
			}
			else{
				en[b]=++idx;
				p[idx]=b;
				en[c]=++idx;
				p[idx]=c;
			}
		}
		else{
			adj[b][c]=adj[c][b]=true;
		}
	}
	
	//dfs
	int cnt=0;
	for(int i=1;i<=n;++i)
		if(!visited[i]) ++cnt,dfs(i);
		
	printf("%d\n",cnt);
}
