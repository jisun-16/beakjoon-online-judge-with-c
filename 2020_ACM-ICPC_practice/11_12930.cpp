#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

const int inf=987654321;
int n,graph[21][21][2],ans=inf;

struct node{
	int x,d1,d2;
	node(int x,int d1,int d2):x(x),d1(d1),d2(d2) {}
};

bool operator<(node a,node b){
	return a.d1*a.d2>b.d1*b.d2;
}

void _dijkstra(){
	int dist[21];
	for(int i=0;i<n;i++) dist[i]=inf;
	priority_queue<node> pq;
	
	pq.push(node(0,0,0));
	dist[0]=0;
	while(!pq.empty()){
		node cur=pq.top();
		pq.pop();
		
		if(dist[cur.x]<cur.d1*cur.d2) continue;
		
		for(int i=0;i<n;i++){
			if(graph[cur.x][i][0]==-1) continue;
			
			int dd=(graph[cur.x][i][0]+cur.d1)*(graph[cur.x][i][1]+cur.d2);
			if(dist[i]>dd){
				dist[i]=dd;
				pq.push(node(i,graph[cur.x][i][0]+cur.d1,graph[cur.x][i][1]+cur.d2));
			}
		}
	}
	
	ans=dist[1];
}

int main(){
	cin>>n;
	for(int k=0;k<2;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				char temp;
				cin>>temp;
				graph[i][j][k]=(temp=='.')?-1:temp-'0';
			}
	
	_dijkstra();
	
	if(ans!=inf) cout<<ans<<'\n';
	else cout<<-1<<'\n';
}
