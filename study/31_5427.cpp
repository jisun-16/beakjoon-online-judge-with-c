#include<cstdio>
#include<queue>

using namespace std;

#define pii pair<int,int>

char arr[1000][1000];
int T,W,H,dx[]={-1,0,1,0},dy[]={0,-1,0,1},t[1000][1000];

bool avail(pii n){
	return n.first>=0&&n.first<H&&n.second>=0&&n.second<W&&arr[n.first][n.second]!='#';
}

int main(){
	scanf("%d",&T);
	while(T--){
		int X,Y,ans=987654321;
		queue<pii> sang, fire, chk;
		bool v1[1000][1000]={0,},v2[1000][1000]={0,};
		
		scanf("%d %d",&W,&H);
		
		for(int i=0;i<H;++i){
			scanf("%s",&arr[i]);
			for(int j=0;j<W;++j){
				t[i][j]=987654321;
				if(arr[i][j]=='@'){
					sang.push({i,j});
					v2[i][j]=true;
				}
				else if(arr[i][j]=='*'){
					fire.push({i,j});
					t[i][j]=0;
					v1[i][j]=true;
				}
				if(i==0||i==H-1||j==0||j==W-1){
					if(arr[i][j]=='.')
						chk.push({i,j});
					else if(arr[i][j]=='@')
						ans=1;
				}
			}
		}
			
		int tt=1;
		while(!fire.empty()){
			int temp=fire.size();
			while(temp--){
				pii now=fire.front();
				fire.pop();
				for(int d=0;d<4;d++){
					pii next=now;
					next.first+=dx[d];next.second+=dy[d];
					if(!avail(next)) continue;
					if(v1[next.first][next.second]) continue;
					if(t[next.first][next.second]<tt) continue;
					v1[next.first][next.second]=true;
					t[next.first][next.second]=tt;
					fire.push(next);
				}
			}
			tt++;
		}
		
		tt=1;
		t[sang.front().first][sang.front().second]=0;
		while(!sang.empty()){
			int temp=sang.size();
			while(temp--){
				pii now=sang.front();
				sang.pop();
				for(int d=0;d<4;d++){
					pii next=now;
					next.first+=dx[d];next.second+=dy[d];
					if(!avail(next)) continue;
					if(v2[next.first][next.second]) continue;
					if(t[next.first][next.second]<=tt) continue;
					v2[next.first][next.second]=true;
					t[next.first][next.second]=-tt;
					sang.push(next);
				}
			}
			tt++;
		}
		
		while(!chk.empty()){
			pii now=chk.front();
			chk.pop();
			if(t[now.first][now.second]<=0&&ans>-t[now.first][now.second]+1){
				ans=-t[now.first][now.second]+1;
			}
		}
		
		if(ans==987654321) printf("IMPOSSIBLE\n");
		else printf("%d\n",ans);
	}
}
