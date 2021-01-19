#include<cstdio>
#include<queue>
#define pii pair<int,int>
#define x first
#define y second
#define inf 987654321

using namespace std;

int R,C,t[50][50],dx[]={-1,1,0,0},dy[]={0,0,-1,1};
char arr[50][50];
pii D,S;
queue<pii> q;

bool avail(pii n){
	return n.x>=0&&n.x<R&&n.y>=0&&n.y<C&&arr[n.x][n.y]!='X';
}

int main(){
	scanf("%d %d",&R,&C);
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j){
			scanf(" %1c",&arr[i][j]);
			t[i][j]=inf;
			if(arr[i][j]=='*'){
				q.push({i,j});
				t[i][j]=0;
			}
			else if(arr[i][j]=='D')
				D={i,j};
			else if(arr[i][j]=='S')
				S={i,j};
		}
	
	int tt=1;
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			pii now=q.front();
			q.pop();
			for(int d=0;d<4;++d){
				pii next=now;
				next.x+=dx[d];next.y+=dy[d];
				if(!avail(next)) continue;
				if(arr[next.x][next.y]=='D') continue;
				if(t[next.x][next.y]!=inf) continue;
				t[next.x][next.y]=tt;
				q.push(next);
			}
		}
		++tt;
	}
	
	q.push(S);
	t[S.x][S.y]=0;
	tt=1;
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			pii now=q.front();
			q.pop();
			for(int d=0;d<4;++d){
				pii next=now;
				next.x+=dx[d];next.y+=dy[d];
				if(!avail(next)) continue;
				if(t[next.x][next.y]<=0) continue;
				if(t[next.x][next.y]<tt+1) continue;
				t[next.x][next.y]=-tt;
				q.push(next);
			}
		}
		++tt;
	}
	
	if(t[D.x][D.y]<0) printf("%d\n",-t[D.x][D.y]);
	else printf("KAKTUS\n");
}
