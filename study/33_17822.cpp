#include<cstdio>
#include<queue>
using namespace std;
int N,M,T,num[51][50],ans,total,cnt;
int main(){
	scanf("%d %d %d",&N,&M,&T);
	for(int i=1;i<=N;++i)
		for(int j=0;j<M;++j) {
			scanf("%d",&num[i][j]);
			total+=num[i][j];
		}
	
	cnt=N*M;
	while(T--){
		int x,d,k;
		scanf("%d %d %d",&x,&d,&k);
		
		if(total==0) break;
		
		for(int i=x;i<=N;i+=x){
			int temp[50]={0,};
			for(int j=0;j<M;++j)
				temp[j]=(d==0)?(num[i][(j-k)<0?j-k+M:j-k]):(num[i][(j+k)>=M?j+k-M:j+k]);
			for(int j=0;j<M;++j)
				num[i][j]=temp[j];
		}
		
		queue<pair<int,int> > q;
		for(int i=1;i<=N;++i)
			for(int j=0;j<M;++j){
				if(num[i][j]==0) continue;
				if(num[i][(j-1)<0?j-1+M:j-1]==num[i][j]||num[i][(j+1)>=M?j+1-M:j+1]==num[i][j])
					q.push({i,j});
				else if(i==1&&num[i+1][j]==num[i][j])
					q.push({i,j});
				else if(i==N&&num[i-1][j]==num[i][j])
					q.push({i,j});
				else if(i>1&&i<N&&(num[i-1][j]==num[i][j]||num[i+1][j]==num[i][j]))
					q.push({i,j});
			}
			
		if(q.empty()){
			double cmp=(double)total/cnt;
			for(int i=1;i<=N;++i)
				for(int j=0;j<M;++j)
					if(num[i][j]){
						if(num[i][j]>cmp) num[i][j]-=1,total-=1;
						else if(num[i][j]<cmp) num[i][j]+=1,total+=1;
					}
		}
		else{
			while(!q.empty()){
				int x=q.front().first,y=q.front().second;
				q.pop();
				total-=num[x][y];
				--cnt;
				num[x][y]=0;
			}
		}
	}
	
	printf("%d\n",total);
}
