#include<iostream>
#include<cmath>

using namespace std;

int N,M,D,en[15][15],arc[3],ans;

void dfs(int idx, int cnt){
	if(cnt==3){
		int chk[15][15]={0,};
		
		for(int t=N;t>0;t--){
			for(int a=0;a<3;a++){
				bool k=false;
				for(int d=1;d<=D;d++){
					int c=arc[a]-d+1;
					while(!k&&c<=arc[a]+d-1){
						int r=t-(d-abs(arc[a]-c));
						if(r>=0&&c>=0&&c<M){
							if(en[r][c]&&chk[r][c]<=t){
								k=true;
								chk[r][c]=t;
							}
						}
						c++;
					}
					if(k) break;
				}
			}
		}
		
		int temp=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(chk[i][j]) temp++;
		if(ans<temp) ans=temp;
		
		return;
	}
	
	if(idx>=M) return;
	for(int i=idx;i<M;i++){
		arc[cnt]=i;
		dfs(i+1,cnt+1);
	}
}

int main(){
	scanf("%d %d %d",&N,&M,&D);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d",&en[i][j]);
	dfs(0,0);
	printf("%d\n",ans);
}
