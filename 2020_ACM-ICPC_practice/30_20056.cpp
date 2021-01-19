#include<cstdio>
#include<queue>
#include<vector>

#define pii pair<int,int>

using namespace std;

struct fire{
	int r,c,m,s,d;//좌표,질량,속력,방향 
	fire(int r,int c,int m,int s,int d):r(r),c(c),m(m),s(s),d(d){}
	fire(){}
};

int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,1,1,1,0,-1,-1,-1};
int N,M,K;
queue<fire> q;

int main(){
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0;i<M;i++){
		int r,c,m,d,s;
		scanf("%d %d %d %d %d",&r,&c,&m,&s,&d);
		r--;c--;
		q.push(fire(r,c,m,s,d));
	}
	
	while(K--){
		vector<fire> arr[50][50];
		
		while(!q.empty()){
			fire now=q.front();
			fire next=now;
			q.pop();
			int nr=(now.r+dx[now.d]*now.s)%N,nc=(now.c+dy[now.d]*now.s)%N;
			nr=(nr+N)%N;
			nc=(nc+N)%N;
			next.r=nr;next.c=nc;
			arr[nr][nc].push_back(next);
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(arr[i][j].size()==0) continue;
				else if(arr[i][j].size()==1) q.push(arr[i][j][0]);
				else{
					int tm=0,ts=0;
					bool odd=true,even=true;
					for(int l=0;l<arr[i][j].size();l++){
						tm+=arr[i][j][l].m;
						ts+=arr[i][j][l].s;
						if(arr[i][j][l].d%2==0) odd=false;
						else even=false;
					}
						
					tm/=5;
					if(tm==0) continue;
					
					ts/=arr[i][j].size();
					
					if(odd||even){
						for(int D=0;D<=6;D+=2) q.push(fire(i,j,tm,ts,D));
					}
					else{
						for(int D=1;D<=7;D+=2) q.push(fire(i,j,tm,ts,D));
					}
				}
			}
		}
	}
	
	int ans=0;
	while(!q.empty()){
		//printf("%d %d %d %d %d\n",q.front().r,q.front().c,q.front().m,q.front().s,q.front().d);
		ans+=q.front().m;
		q.pop();
	}
	
	printf("%d\n",ans);
}
